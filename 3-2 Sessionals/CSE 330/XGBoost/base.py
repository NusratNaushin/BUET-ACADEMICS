import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import BaggingClassifier
from sklearn.datasets import load_breast_cancer
import xgboost as xgb
import random

# -------------------- Reproducibility --------------------
def set_seed(seed=42): 
    random.seed(seed)
    np.random.seed(seed)

set_seed(42)

# -------------------- Load the dataset --------------------
data = load_breast_cancer()

# -------------------- Separate features and target --------------------
X = data.data
y = data.target

# -------------------- Train-test split (80%-20%) --------------------
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# -------------------- Scale the features --------------------
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# -------------------- Base Learner --------------------
base_model = LogisticRegression(max_iter=5000)
base_model.fit(X_train, y_train)

y_pred_base = base_model.predict(X_test)
lr_acc = accuracy_score(y_test, y_pred_base)

# -------------------- Bagging with Base Learner --------------------
bagging_model = BaggingClassifier(
    estimator=LogisticRegression(max_iter=5000),
    n_estimators=20,
    random_state=42
)

bagging_model.fit(X_train, y_train)
y_pred_bag = bagging_model.predict(X_test)
bagging_acc = accuracy_score(y_test, y_pred_bag)

# -------------------- XGBoost --------------------
param_grid = [
    {"n_estimators": 5, "max_depth": 1, "learning_rate": 0.8},   # intentionally weak
    {"n_estimators": 50, "max_depth": 3, "learning_rate": 0.1},
    {"n_estimators": 100, "max_depth": 4, "learning_rate": 0.05},
    {"n_estimators": 200, "max_depth": 6, "learning_rate": 0.3}, # may overfit
]
xgb_best_acc = 0
xgb_poor_acc = 1
best_params = None
poor_params = None

for params in param_grid:
    model = xgb.XGBClassifier(
        n_estimators=params["n_estimators"],
        max_depth=params["max_depth"],
        learning_rate=params["learning_rate"],
        eval_metric="logloss",
        random_state=42
    )

    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    acc = accuracy_score(y_test, y_pred)

    if acc > xgb_best_acc:
        xgb_best_acc = acc
        best_params = params   # Save the best parameters

    if acc < xgb_poor_acc:
        xgb_poor_acc = acc
        poor_params = params   # Save the worst parameters

# -------------------- Final Output --------------------
print("\n" + "="*60)
print("RESULTS")
print("="*60)
print(f"Base Learner Accuracy: {round(lr_acc, 4)}")
print(f"Bagging Accuracy: {round(bagging_acc, 4)}")
print("-" * 60)
print(f"XGBoost Worst Accuracy: {round(xgb_poor_acc, 4)} with params: {poor_params}")
print(f"XGBoost Best Accuracy: {round(xgb_best_acc, 4)} with params: {best_params}")
print("=" * 60)