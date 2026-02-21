import numpy as np
import random
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import BaggingClassifier
import xgboost as xgb
from tensorflow.keras.datasets import mnist

# -------------------- Reproducibility --------------------
def set_seed(seed=42):
    random.seed(seed)
    np.random.seed(seed)

set_seed(42)

# -------------------- Load MNIST --------------------
(X_train_full, y_train_full), (X_test, y_test) = mnist.load_data()

# Flatten images (28x28 → 784)
X_train_full = X_train_full.reshape(-1, 784)
X_test = X_test.reshape(-1, 784)

# Normalize
X_train_full = X_train_full / 255.0
X_test = X_test / 255.0

# Optional validation split
X_train, X_val, y_train, y_val = train_test_split(
    X_train_full, y_train_full, test_size=0.2, random_state=42
)

# -------------------- Base Learner --------------------
base_model = LogisticRegression(max_iter=2000)
base_model.fit(X_train, y_train)

y_pred_base = base_model.predict(X_test)
lr_acc = accuracy_score(y_test, y_pred_base)

# -------------------- Bagging --------------------
bagging_model = BaggingClassifier(
    estimator=LogisticRegression(max_iter=2000),
    n_estimators=10,
    random_state=42
)

bagging_model.fit(X_train, y_train)
y_pred_bag = bagging_model.predict(X_test)
bagging_acc = accuracy_score(y_test, y_pred_bag)

# -------------------- XGBoost --------------------
param_grid = [
    {"n_estimators": 20, "max_depth": 3, "learning_rate": 0.3},
    {"n_estimators": 100, "max_depth": 4, "learning_rate": 0.1},
    {"n_estimators": 200, "max_depth": 6, "learning_rate": 0.05},
]

xgb_best_acc = 0
xgb_poor_acc = 1

for params in param_grid:
    model = xgb.XGBClassifier(
        objective="multi:softmax",
        num_class=10,
        n_estimators=params["n_estimators"],
        max_depth=params["max_depth"],
        learning_rate=params["learning_rate"],
        random_state=42
    )

    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    acc = accuracy_score(y_test, y_pred)

    if acc > xgb_best_acc:
        xgb_best_acc = acc

    if acc < xgb_poor_acc:
        xgb_poor_acc = acc

# -------------------- Final Output --------------------
print("\n" + "="*60)
print("RESULTS (MNIST)")
print("="*60)
print(f"Base Learner Accuracy: {round(lr_acc, 4)}")
print(f"Bagging Accuracy: {round(bagging_acc, 4)}")
print("-" * 60)
print(f"XGBoost Worst Accuracy: {round(xgb_poor_acc, 4)}")
print(f"XGBoost Best Accuracy: {round(xgb_best_acc, 4)}")
print("=" * 60)