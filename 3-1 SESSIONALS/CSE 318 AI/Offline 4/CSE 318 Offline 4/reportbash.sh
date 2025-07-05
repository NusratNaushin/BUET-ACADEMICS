#!/bin/bash
javac *.java

java DecisionTree Datasets/Iris.csv ig 3
java DecisionTree Datasets/Iris.csv igr 3
java DecisionTree Datasets/Iris.csv nwig 3

