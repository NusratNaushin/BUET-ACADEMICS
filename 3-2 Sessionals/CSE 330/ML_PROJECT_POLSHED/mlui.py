import streamlit as st
import tensorflow as tf
import pickle
import numpy as np
import torch  # এটি মিসিং ছিল
from PIL import Image
from transformers import AutoImageProcessor, AutoModelForImageClassification
from tensorflow.keras.preprocessing.sequence import pad_sequences
from tensorflow.keras.preprocessing.image import img_to_array
from tensorflow.keras.applications.vgg16 import VGG16, preprocess_input
from tensorflow.keras.models import Model
import re

# ---------------- CONFIG ----------------
MODEL_PATH = "dog_caption_model.keras"
TOKENIZER_PATH = "tokenizer.pkl"
MAX_LENGTH = 35   

# ---------------- LOAD MODELS ----------------

@st.cache_resource
def load_all_models():
    # Caption Model
    cap_model = tf.keras.models.load_model(MODEL_PATH)
    
    # VGG16
    base_vgg = VGG16(weights="imagenet")
    vgg = Model(inputs=base_vgg.inputs, outputs=base_vgg.layers[-2].output)
    
    # Breed Model
    processor = AutoImageProcessor.from_pretrained("wesleyacheng/dog-breeds-multiclass-image-classification-with-vit")
    b_model = AutoModelForImageClassification.from_pretrained("wesleyacheng/dog-breeds-multiclass-image-classification-with-vit")
    b_model.eval()
    
    return cap_model, vgg, processor, b_model

model, model_vgg, breed_processor, breed_model = load_all_models()

with open(TOKENIZER_PATH, "rb") as f:
    tokenizer = pickle.load(f)

# ---------------- HELPER FUNCTIONS ----------------

def extract_features(image):
    img = image.resize((224, 224))
    img = img_to_array(img)
    img = np.expand_dims(img, axis=0)
    img = preprocess_input(img)
    feature = model_vgg.predict(img, verbose=0)
    return feature

def idx_to_word(integer, tokenizer):
    for word, index in tokenizer.word_index.items():
        if index == integer:
            return word
    return None

def predict_caption(image_feature):
    in_text = "startseq"
    for _ in range(MAX_LENGTH):
        sequence = tokenizer.texts_to_sequences([in_text])[0]
        sequence = pad_sequences([sequence], maxlen=MAX_LENGTH)
        yhat = model.predict([image_feature, sequence], verbose=0)
        yhat = np.argmax(yhat)
        word = idx_to_word(yhat, tokenizer)
        if word is None or word == "endseq":
            break
        in_text += " " + word
    return in_text.replace("startseq", "").strip()

# ---------------- MAIN GENERATION FUNCTION ----------------

def generate_final_output(image):
    inputs = breed_processor(images=image, return_tensors="pt")
    with torch.no_grad():
        outputs = breed_model(**inputs)
    
    probs = torch.nn.functional.softmax(outputs.logits, dim=-1)
    confidence, idx = torch.max(probs, dim=-1)
    
    breed = "dog"
    if confidence.item() > 0.1: 
        breed = breed_model.config.id2label[idx.item()].replace("_", " ")

    feature = extract_features(image)
    base_caption = predict_caption(feature)

    if "dog" in base_caption.lower():
        final_caption = re.sub(r'dog', breed, base_caption, flags=re.IGNORECASE)
    else:
        final_caption = base_caption
    
    return final_caption

# ---------------- STREAMLIT UI ----------------

st.set_page_config(page_title="Dog Caption Generator", layout="centered")
st.title("🐶 Dog Image Caption Generator")
st.write("Upload a dog image and generate a specific caption.")

uploaded_file = st.file_uploader("Upload an Image", type=["jpg", "jpeg", "png"])

if uploaded_file is not None:
    image = Image.open(uploaded_file).convert("RGB")
    st.image(image, caption="Uploaded Image", use_container_width=True)

    with st.spinner("Analyzing dog breed and generating caption..."):
        # মূল ফাংশন কল
        final_result = generate_final_output(image)

    st.subheader("Generated Caption:")
    st.success(final_result)