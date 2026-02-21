# -------------------- Full XGBoost Pipeline Example --------------------
import pandas as pd
import numpy as np
import xgboost as xgb
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
import random

# -------------------- Reproducibility --------------------
def set_seed(seed=42):
    random.seed(seed)
    np.random.seed(seed)

set_seed(42)

# -------------------- Load & Prepare Dataset --------------------
data = load_breast_cancer()
X = data.data
y = data.target

# Train-Test Split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# Scaling (optional, not needed for tree-based, just to show syntax)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# -------------------- XGBoost Parameters --------------------
params = {
    'objective': 'binary:logistic',  # Classification
    'max_depth': 4,                  # Tree depth
    'learning_rate': 0.05,           # Step size
    'n_estimators': 100,             # Number of trees
    'subsample': 0.8,                # Row subsampling
    'colsample_bytree': 0.8,         # Column subsampling
    'gamma': 1,                       # Min loss reduction for split
    'min_child_weight': 1,            # Min hessian sum per leaf
    'use_label_encoder': False,
    'eval_metric': 'logloss',         # Binary classification
    'random_state': 42
}

# -------------------- Train with Early Stopping --------------------
# Use validation set for early stopping
model = xgb.XGBClassifier(**params)
model.fit(
    X_train, y_train,
    eval_set=[(X_test, y_test)],
    early_stopping_rounds=10,
    verbose=False
)

# -------------------- Predict & Evaluate --------------------
preds = model.predict(X_test)
acc = accuracy_score(y_test, preds)
print(f"Test Accuracy: {acc:.4f}")

# -------------------- Feature Importance --------------------
# Gain, Cover, Weight
import matplotlib.pyplot as plt
xgb.plot_importance(model, importance_type='gain')
plt.title("Feature Importance by Gain")
plt.show()

xgb.plot_importance(model, importance_type='cover')
plt.title("Feature Importance by Cover")
plt.show()

xgb.plot_importance(model, importance_type='weight')
plt.title("Feature Importance by Weight")
plt.show()

# -------------------- Save & Load Model --------------------
model.save_model("xgb_model.json")
loaded_model = xgb.XGBClassifier()
loaded_model.load_model("xgb_model.json")
loaded_preds = loaded_model.predict(X_test)
print(f"Loaded Model Accuracy: {accuracy_score(y_test, loaded_preds):.4f}")

