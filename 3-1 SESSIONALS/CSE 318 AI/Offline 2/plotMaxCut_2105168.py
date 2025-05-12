import csv
import matplotlib.pyplot as plt
import numpy as np
import re

graph1 = 1
graph2 = 10

def plot_from_csv(csv_file):
    with open(csv_file,'r') as f:
        reader = list(csv.reader(f))
    
    data = reader[2:]

    graph_names = []

    random_cut = []
    greedy_cut =[]
    semi_greedy_cut_value = []
    #semi_greedy_cut_card = []
    local_search_cut =[]
    grasp_cut =[]
    
    for row in data:
        try:
            name = row[0]
            match = re.match(r'g(\d+)', name)
            if not match:
                continue
            number = int(match.group(1))
            if number < graph1 or graph2 < number:
                continue
            

            rand = int(row[3])
            greed = int(row[4])
            semi = int(row[5])
            grasp = int(row[12])
            local = int(row[8])
        except (ValueError , IndexError):
            continue


        graph_names.append(name)
        random_cut.append(rand)
        greedy_cut.append(greed)
        semi_greedy_cut_value.append(semi)
        grasp_cut.append(grasp)
        local_search_cut.append(local)

    index = np.arange(len(graph_names))
    width = 0.15

    plt.figure(figsize=(14,7))


    plt.bar(index - 2*width , random_cut , width=width ,label = 'Randomized' , color= 'skyblue')
    plt.bar(index - width , greedy_cut , width=width ,label='Greedy' , color= 'orange')
    plt.bar(index  , semi_greedy_cut_value , width=width ,label='Semi-Greedy', color= 'gray')
    plt.bar(index + width , grasp_cut , width=width ,label='GRASP' , color= 'gold')
    plt.bar(index + 2*width , local_search_cut , width=width ,label='Local Search' , color= 'blue')


    
    plt.xticks(index, graph_names, rotation=45)
    plt.xlabel("Graphs")
    plt.ylabel("Cut Value")
    plt.title("Max Cut for Graphs g1 to g10")
    plt.legend()
    plt.grid(True, axis='y', linestyle='--', linewidth=0.5)
    plt.tight_layout()
    plt.savefig("max_cut_g1_to_g10.png")
    plt.show()

plot_from_csv("2105168.csv")
