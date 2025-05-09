import csv
import matplotlib.pyplot as plt
import numpy as np
import re
graph1 = 1
graph2 = 10
def plot_from_csv(csv_path):
    with open(csv_path, 'r') as f:
        reader = list(csv.reader(f))

    data = reader[2:]  # Skip the two header rows

    graph_names = []
    randomized_values = []
    greedy_values = []
    semi_greedy_values = []
    grasp_values = []
    local_search_values = []

    for row in data:
        try:
            name = row[0]
            # Only process graphs g1 to g10
            match = re.match(r'g(\d+)', name)
            if not match:
                continue
            number = int(match.group(1))
            if number < graph1 or number > graph2:
                continue

            rand = int(row[3])
            greed = int(row[4])
            semi = int(row[5])
            grasp = int(row[13])
            local = int(row[8])
        except (ValueError, IndexError):
            continue

        graph_names.append(name)
        randomized_values.append(rand)
        greedy_values.append(greed)
        semi_greedy_values.append(semi)
        grasp_values.append(grasp)
        local_search_values.append(local)

    indices = np.arange(len(graph_names))
    width = 0.15

    plt.figure(figsize=(14, 7))
    plt.bar(indices - 2*width, randomized_values, width=width, label='Randomized', color='skyblue')
    plt.bar(indices - width, greedy_values, width=width, label='Greedy', color='orange')
    plt.bar(indices, semi_greedy_values, width=width, label='Semi-Greedy', color='gray')
    plt.bar(indices + width, grasp_values, width=width, label='GRASP', color='gold')
    plt.bar(indices + 2*width, local_search_values, width=width, label='Local Search', color='blue')

    plt.xticks(indices, graph_names, rotation=45)
    plt.xlabel("Graphs")
    plt.ylabel("Cut Value")
    plt.title("Max Cut for Graphs g1 to g10")
    plt.legend()
    plt.grid(True, axis='y', linestyle='--', linewidth=0.5)
    plt.tight_layout()
    plt.savefig("max_cut_g1_to_g10.png")
    plt.show()

plot_from_csv("2105168.csv")
