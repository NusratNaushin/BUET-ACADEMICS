import csv
import os 
import re
from ghoradim import Graph , Algorithm




def sort_files(s):
    parts = re.split(r'(\d+)', s)
    processed = []

    for part in parts:
        if part.isdigit():
            processed.append(int(part))
        else:
            processed.append(part.lower())
    
    return processed



def read_a_input_file(filepath):
    with open(filepath , 'r') as f:
        n , m = map(int , f.readline().split())
        G = Graph(n,m)
        for _ in range(m):
            u,v,w = map(int , f.readline().split())
            G.add_edge(u,v,w)
    return G

def run_all_input_files(input_directory , output_csv , knownbestdictionary):
    results = []


    for filename in sorted(os.listdir(input_directory), key=sort_files):
        if filename.endswith(".rud"):
            filepath = os.path.join(input_directory, filename)
            G = read_a_input_file(filepath)

            name = filename[:-4]
            n = len(G.nodes)
            m = len(G.edges) // 2

            rand_cut , Xrand , Yrand = Algorithm.RandomizedMaxCut(G , 10)
            _,_, greedy_cut = Algorithm.Greedy(G)
            XsemiValue , YsemiValue , semi_value = Algorithm.SemiGreedyValueBased(G , 0.9 )
            Xcard , Ycard , semi_card = Algorithm.SemiGreedy_CardinalityBasedRCL(G , 5)
            _, _, local_cut_value, local_iters_value = Algorithm.LocalSearch(G, XsemiValue, YsemiValue)
            _, _, local_cut_card, local_iters_card = Algorithm.LocalSearch(G, Xcard, Ycard)

            _, _, grasp_cut_1, grasp_iters_1 = Algorithm.GRASP(G, 2, 1, 0.9, 5)
            _, _, grasp_cut_2, grasp_iters_2 = Algorithm.GRASP(G, 2, 2, 0.9, 5)           


            results.append([

                name, n, m,
                int(rand_cut), greedy_cut, semi_value,semi_card,
                local_iters_value, local_cut_value,
                local_iters_card, local_cut_card,
                grasp_iters_1, grasp_cut_1,
                grasp_iters_2, grasp_cut_2,
                knownbestdictionary.get(name, "")

            ])
    
    with open(output_csv , 'a' , newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow([
            "Name", "|V|", "|E|",
            "Randomized-1", "Greedy-1", "Semi-Greedy-1","Semi-Greedy-2",
            "Local-1 Iterations", "Local-1 Value",
            "Local-2 Iterations", "Local-2 Value",
            "GRASP-1 Iterations", "GRASP-1 Best Value",
            "GRASP-2 Iterations", "GRASP-2 Best Value",
            "Known Best"
        ])

        writer.writerows(results)

known_best = {

}

run_all_input_files("graph_GRASP/set1", "2105168.csv" , known_best)