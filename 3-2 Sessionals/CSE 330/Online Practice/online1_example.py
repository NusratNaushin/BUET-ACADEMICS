import pandas as pd
import numpy as np

def load_and_fill_nulls(filename, fill_value=0):
    df = pd.read_csv(filename)

    print(f"Dataset loaded successfully!")
    print(f"Shape: {df.shape}")
    print(f"\nFirst few rows:")
    print(df.head())

    print("\nNull values per column before filling:")
    print(df.isnull().sum())

    df = df.fillna(fill_value)

    print("\nNull values per column after filling:")
    print(df.isnull().sum())

    return df

def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# ============================
# MAIN: MINIBATCH TRAINING WITH EPOCHS
# ============================
if __name__ == "__main__":
    df = load_and_fill_nulls("Diabetes Missing Data.csv", fill_value=0)

    X = df.iloc[:, :-1].values
    y = df.iloc[:, -1].values.reshape(-1, 1)

    # Normalize
    X = (X - X.mean(axis=0)) / (X.std(axis=0) + 1e-8)

    n_samples, n_features = X.shape

    # Initialize parameters
    W = np.zeros((n_features, 1))
    b = 0.0

    batch_size = 32
    learning_rate = 0.01
    epochs = 5

    print("\nRunning minibatch training with epochs...\n")

    for epoch in range(epochs):
        for i in range(0, n_samples, batch_size):
            Xb = X[i:i+batch_size]
            yb = y[i:i+batch_size]

            # Forward pass
            preds = Xb @ W + b
            y_hat = sigmoid(preds)

            # Compute gradients
            error = y_hat - yb
            dw = (Xb.T @ error) / len(Xb)
            db = np.mean(error)

            # Update parameters
            W -= learning_rate * dw
            b -= learning_rate * db

        # Optional: compute loss after each epoch
        y_hat_all = sigmoid(X @ W + b)
        loss = -np.mean(y * np.log(y_hat_all + 1e-8) + (1 - y) * np.log(1 - y_hat_all + 1e-8))
        print(f"Epoch {epoch+1}/{epochs}, Loss: {loss:.4f}")

    # ======================
    # Accuracy calculation
    # ======================
    y_pred = sigmoid(X @ W + b)
    y_pred_class = (y_pred >= 0.5).astype(int)
    accuracy = np.mean(y_pred_class == y)

    print("\nTraining completed.")
    print("Final Accuracy:", accuracy)
    print("Final W:", W.ravel())
    print("Final b:", b)
