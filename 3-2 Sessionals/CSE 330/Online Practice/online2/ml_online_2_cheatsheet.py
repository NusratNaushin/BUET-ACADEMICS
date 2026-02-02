# -----------------------------
# ML Online 2 - Cheatsheet
# -----------------------------

import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
from torchvision import datasets, transforms
from torch.utils.data import DataLoader

# -----------------------------
# Reproducibility
# -----------------------------
import random, numpy as np

def set_seed(seed=42):
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    if torch.cuda.is_available():
        torch.cuda.manual_seed(seed)

set_seed(42)

# -----------------------------
# Device
# -----------------------------
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# -----------------------------
# Optimizer Table
# -----------------------------
# SGD: simple, fixed lr, optional momentum
# Adam: adaptive lr, combines momentum + RMSProp

# -----------------------------
# Fully Connected Neural Network (FNN) Template
# -----------------------------
class FNN(nn.Module):
    def __init__(self, input_size=28*28, hidden_size=128, num_classes=10):
        super(FNN, self).__init__()
        self.fc1 = nn.Linear(input_size, hidden_size)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(hidden_size, num_classes)

    def forward(self, x):
        x = x.view(x.size(0), -1)  # flatten
        x = self.relu(self.fc1(x))
        x = self.fc2(x)
        return x

# -----------------------------
# CNN Template
# -----------------------------
class SimpleCNN(nn.Module):
    def __init__(self, input_channels=1, num_classes=10):
        super(SimpleCNN, self).__init__()
        self.conv1 = nn.Conv2d(input_channels, 16, 3, stride=1, padding=1)
        self.relu = nn.ReLU()
        self.pool = nn.MaxPool2d(2,2)
        self.gap = nn.AdaptiveAvgPool2d((1,1))
        self.fc = nn.Linear(16, num_classes)

    def forward(self, x):
        x = self.conv1(x)
        x = self.relu(x)
        x = self.pool(x)
        x = self.gap(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x

# -----------------------------
# Data Preparation Example (MNIST)
# -----------------------------
transform = transforms.Compose([
    transforms.Resize((64, 64)),  # design choice
    transforms.ToTensor(),
    transforms.Normalize((0.1307,), (0.3081,))  # dataset stats
])

train_dataset = datasets.MNIST(root='./data', train=True, download=True, transform=transform)
train_loader = DataLoader(train_dataset, batch_size=32, shuffle=True)

# -----------------------------
# Training Loop Skeleton
# -----------------------------
model = SimpleCNN().to(device)
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

num_epochs = 5
for epoch in range(num_epochs):
    model.train()
    running_loss, correct, total = 0.0, 0, 0

    for images, labels in train_loader:
        images, labels = images.to(device), labels.to(device)
        optimizer.zero_grad()          # clear gradients
        outputs = model(images)        # forward pass
        loss = criterion(outputs, labels)
        loss.backward()                # backward pass
        optimizer.step()               # update weights

        running_loss += loss.item() * images.size(0)
        _, predicted = outputs.max(1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

    epoch_loss = running_loss / total
    epoch_acc = 100.0 * correct / total
    print(f"Epoch [{epoch+1}/{num_epochs}] Loss: {epoch_loss:.4f}, Accuracy: {epoch_acc:.2f}%")

# -----------------------------
# Notes:
# - FNN: flatten input -> fc -> relu -> fc
# - CNN: conv -> relu -> pool -> (gap optional) -> flatten -> fc
# - AdaptiveAvgPool2d((1,1)): avoids manual flatten size
# - ReLU: introduces non-linearity
# - MaxPool2d: reduces spatial size, translation invariance
# - Optimizer: Adam for adaptive lr, SGD for simple cases
