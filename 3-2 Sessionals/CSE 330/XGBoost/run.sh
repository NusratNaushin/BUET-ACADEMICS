#!/bin/bash

# file name input nibo

filepath=$1


python3 -m venv venv
source venv/bin/activate
pip install tensorflow-cpu

pip install --upgrade pip
pip install numpy pandas scikit-learn xgboost scipy
pip install matplotlib xgboost scikit-learn

python $filepath