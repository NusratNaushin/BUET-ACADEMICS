import csv
import matplotlib.pyplot as plt

def read_csv(filename):
    data = []  

    with open(filename, 'r') as file:
        reader = csv.reader(file)
        header = next(reader)  

        for row in reader:
            record = {
                "Dataset": row[0],
                "Criterion": row[1],
                "MaxDepth": int(row[2]),
                "AvgAccuracy": float(row[3]),
                "NumNodes": int(row[4]),
                "ActualMaxDepth": int(row[5])
            }
            data.append(record)

    return data

def plot_accuracy(data):
    datasets = set([row["Dataset"] for row in data])
    criteria = set([row["Criterion"] for row in data])

    for dataset in datasets:
        plt.figure()
        for criterion in criteria:
            x = []
            y = []
            for row in data:
                if row["Dataset"] == dataset and row["Criterion"] == criterion:
                    x.append(row["MaxDepth"])
                    y.append(row["AvgAccuracy"])
            plt.plot(x, y, marker='o', label=criterion)

        plt.title("Accuracy vs Max Depth - " + dataset)
        plt.xlabel("Max Depth")
        plt.ylabel("Average Accuracy (%)")
        plt.legend()
        plt.grid(True)
        plt.savefig(dataset + "_accuracy.png")
        plt.show()

def plot_nodes(data):
    datasets = set([row["Dataset"] for row in data])
    criteria = set([row["Criterion"] for row in data])

    for dataset in datasets:
        plt.figure()
        for criterion in criteria:
            x = []
            y = []
            for row in data:
                if row["Dataset"] == dataset and row["Criterion"] == criterion:
                    x.append(row["MaxDepth"])
                    y.append(row["NumNodes"])
            plt.plot(x, y, marker='s', label=criterion)

        plt.title("Number of Nodes vs Max Depth - " + dataset)
        plt.xlabel("Max Depth")
        plt.ylabel("Node Count")
        plt.legend()
        plt.grid(True)
        plt.savefig(dataset + "_nodes.png")
        plt.show()

def main():
    data = read_csv("results.csv")
    plot_accuracy(data)
    plot_nodes(data)

main()
