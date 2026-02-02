import pandas as pd
import numpy as np

np.random.seed(42)

# 1. Windowing Average Imputation
def windowing_average_imputation(x, k=3):
    # TODO: Windowing average imputation
    x_imputed = x.copy()
    n_samples, n_features = x.shape 
    for i in range(n_samples):
        for j in range(n_features):
            if np.isnan(x_imputed[i, j]):
                start = max(0, i - k)
                end = min(n_samples, i + k + 1)
                window = x[start:end, j]
                window_mean = np.nanmean(window)
                x_imputed[i, j] = window_mean
    return x_imputed #of shape as x

# 2. Tanh
def tanh(x):
    # TODO: Tanh function
    value = (np.exp(x) -np.exp(-x))/(np.exp(x) + np.exp(-x))
    return value # of shape as x

# 3. Tanh gradient
def tanh_gradient(x, dout=1):
    # TODO: Tanh gradient
    grad = ( 1 - tanh(x)**2)*dout
    return grad # of shape as x

# 4. MAE
def mae(y_pred, y_true):
    # TODO: MAE loss
    loss = np.mean (np.abs(y_pred - y_true))
    return loss # only a scalar value

# 5. MAE gradient
def mae_gradient(y_pred, y_true):
    # TODO: MAE gradient
    n = y_pred.shape[0]
    grad = np.mean(np.sign(y_pred - y_true))/n
    return grad # of shape as y_pred

# 6. Inference on test data and evaluate MAE
def inference(df_test, W, b, X):
    # TODO: Load test data and evaluate MAE.
    X_test = df_test.iloc[:, :-1].values
    y_test = df_test.iloc[:, -1].values.reshape(-1, 1)
    X_test = windowing_average_imputation(X_test, k=10)
    
    outputs = X_test @ W + b
    preds = tanh(outputs)
    test_mae = mae(preds, y_test)
    return test_mae

def mse_loss(y_pred, y_true):
    n = len(y_pred)
    loss = (1/n) * np.sum((y_pred - y_true) ** 2)
    return loss


def relu(x):
    return np.maximum(0,x)

def relu_gradient(x, dout = 1):
    grad = np.where(x>0 , 1, 0) 
    return grad*dout


def binary_cross_entropy(y_pred, y_true):
    epsilon_to_avoid_log_0 = 1e-15
    y_pred = np.clip(y_pred, epsilon_to_avoid_log_0, 1 - epsilon_to_avoid_log_0)
    loss = -np.mean(
        (y_true*np.log(y_pred))+ (1-y_true)*np.log(1-y_pred)
        )
    
    return loss

def binary_cross_entropy_gradient(y_pred, y_true):
    epsilon_to_avoid_log_0 = 1e-15
    y_pred = np.clip(y_pred, epsilon_to_avoid_log_0, 1 - epsilon_to_avoid_log_0)
    n=y_true.shape[0]
    grad = (y_pred - y_true)/(y_pred*(1 - y_pred)*n)
    return grad



def min_max_normalization(x):
    x_min = np.min(x, axis = 0)
    x_max = np.max(x, axis = 0)
    
    x_normalized = (x-x_min)/(x_max - x_min + 1e-8)

def log_loss(y_pred, y_true):
    epsilon_to_avoid_log_0 = 1e-15
    y_pred = np.clip(y_pred, epsilon_to_avoid_log_0, 1 - epsilon_to_avoid_log_0)
    N = y_true.shape[0]
    loss = -np.mean(
        (y_true*np.log(y_pred))+ (1-y_true)*np.log(1-y_pred)
        )       

    return loss

def log_loss_gradient(y_pred, y_true):
    epsilon_to_avoid_log_0 = 1e-15
    y_pred = np.clip(y_pred, epsilon_to_avoid_log_0, 1 - epsilon_to_avoid_log_0)
    n=y_true.shape[0]
    grad = (y_pred - y_true)/(y_pred*(1 - y_pred)*n)
    return grad

def mean_imputation(X):
    X_imputed = X.copy()
    col_mean = np.nanmean(X_imputed, axis=0)
    inds = np.where(np.isnan(X_imputed))
    X_imputed[inds] = np.take(col_mean, inds[1])
    return X_imputed


def leaky_relu(x, alpha=0.01):
    return np.where(x>0,x , alpha*x)

def leaky_relu_gradient(x,dout=1,alpha=0.01):
    grad = np.where(x>0,1,alpha)
    return grad*dout

def huber_loss(y_pred, y_true, delta=1.0):
    error = y_pred - y_true
    is_small_error = np.abs(error) <= delta
    quadratic = 0.5 * error**2
    linear = delta*abs(error) - 0.5*delta**2
    
    loss = np.where(is_small_error, quadratic, linear)
    return np.mean(loss)
    
    
def huber_loss_gradient(y_pred, y_true, delta=1.0):
    error = y_pred - y_true
    is_small_error = np.abs(error) <= delta
    grad = np.where(is_small_error, error, delta * np.sign(error))
    n = y_true.shape[0]
    return grad / n

def rmse(y_pred, y_true):
    return np.sqrt(np.mean((y_pred - y_true) ** 2))

# ============================
# MAIN: MINIBATCH TRAINING + ACCURACY
# ============================
if __name__ == "__main__":
    df = pd.read_csv("train_data.csv", header=None)
    print("Data size:", df.shape)

    X = df.iloc[:, :-1].values
    y = df.iloc[:, -1].values.reshape(-1, 1)

    print("NaN values in X before imputation:", np.isnan(X).sum())
    print("Performing windowing average imputation for missing values...")
    X = windowing_average_imputation(X, k=10)
    print("NaN values in X after imputation:", np.isnan(X).sum())

    n_samples, n_features = X.shape

    # Initialize parameters
    W = np.zeros((n_features, 1))
    b = 0.0

    batch_size = 50
    learning_rate = 0.01
    num_epochs = 20

    print(f"\nTraining for {num_epochs} epochs with learning rate {learning_rate}...\n")

    # Training loop
    for epoch in range(num_epochs):
        epoch_loss = 0.0
        num_batches = 0
        
        # Shuffle data at the beginning of each epoch
        indices = np.random.permutation(n_samples)
        X_shuffled = X[indices]
        y_shuffled = y[indices]
        
        for i in range(0, n_samples, batch_size):
            Xb = X_shuffled[i:i+batch_size]
            yb = y_shuffled[i:i+batch_size]
            
            outputs = Xb @ W + b
            preds = tanh(outputs)
            
            # Compute loss
            batch_loss = mae(preds, yb)
            epoch_loss += batch_loss
            num_batches += 1
            
            # Gradient of loss w.r.t predictions
            dloss_dpreds = mae_gradient(preds, yb)
            
            # Gradient of tanh
            dpreds_doutputs = tanh_gradient(outputs, dout=dloss_dpreds)
            
            # Gradients w.r.t W and b
            dW = Xb.T @ dpreds_doutputs
            db = np.sum(dpreds_doutputs)
            
            # Update weights
            W -= learning_rate * dW
            b -= learning_rate * db
        
        avg_loss = epoch_loss / num_batches
        
        # Calculate accuracy on full dataset
        outputs_all = X @ W + b
        y_pred = tanh(outputs_all)

        mse = mse_loss(y_pred, y)
        
        print(f"Epoch {epoch+1}/{num_epochs} - Loss: {avg_loss:.6f}, MSE: {mse:.4f}")

    print("\n" + "="*50)
    print("Training completed!")
    print("="*50)

    # Final evaluation
    outputs_final = X @ W + b
    preds_final = tanh(outputs_final)
    final_loss = mae(preds_final, y)
    mse_final = mse_loss(preds_final, y)

    print(f"\nFinal MAE Loss: {final_loss:.6f}")
    print(f"Final MSE: {mse_final:.4f}")
    print("\nTrained weights (W):", W.ravel())
    print(f"Trained bias (b): {b:.6f}")

    # ============================
    # INFERENCE ON TEST DATA
    # ============================

    df_test = pd.read_csv("test_data.csv", header=None)

    test_mae = inference(df_test, W, b, X)
    
    print(f"Test MAE: {test_mae:.6f}")
