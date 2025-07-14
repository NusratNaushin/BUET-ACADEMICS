#!/bin/bash

rm -f *.png

VENV_DIR=".venv_plot"

if [ ! -d "$VENV_DIR" ]; then
    python3 -m venv $VENV_DIR
fi

source $VENV_DIR/bin/activate

pip install --quiet matplotlib
python3 plot.py

deactivate
