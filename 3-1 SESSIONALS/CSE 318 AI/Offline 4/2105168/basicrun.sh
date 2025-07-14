#!/bin/bash
find . -name "*.class" -type f -delete

javac *.java
java DecisionTree Datasets/adult.data nwig 1