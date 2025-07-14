#!/bin/bash
rm -f results.csv
echo "Dataset,Criterion,MaxDepth,AvgAccuracy,NumNodes,ActualMaxDepth" > results.csv

javac *.java

datasets=("Datasets/Iris.csv" "Datasets/adult.data")
criteria=("ig" "igr" "nwig")

for dataset in "${datasets[@]}"; do
  for depth in {0..6}; do
    for criterion in "${criteria[@]}"; do
      echo "Running for $dataset | $criterion | depth $depth"
      java DecisionTree "$dataset" "$criterion" "$depth"
    done
  done
done
