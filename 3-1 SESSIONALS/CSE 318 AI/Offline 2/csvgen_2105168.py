import csv
import os 
import re
from main_2105168 import Graph, Algorithm


iterations = 10
alpha = 0.9
k = 5

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

    count=0
    for filename in sorted(os.listdir(input_directory), key=sort_files):
        count += 1
        print("working with file no : " ,count)
        if filename.endswith(".rud"):
            filepath = os.path.join(input_directory, filename)
            G = read_a_input_file(filepath)

            name = filename[:-4]
            n = len(G.nodes)
            m = len(G.edges) // 2

            rand_cut , Xrand , Yrand = Algorithm.RandomizedMaxCut(G , iterations)
            _,_, greedy_cut = Algorithm.Greedy(G)
            XsemiValue , YsemiValue , semi_value = Algorithm.SemiGreedyValueBased(G , alpha )
            Xcard , Ycard , semi_card = Algorithm.SemiGreedy_CardinalityBasedRCL(G , k)
            _, _, local_cut_value, local_iters_value = Algorithm.LocalSearch(G, XsemiValue, YsemiValue)
            _, _, local_cut_card, local_iters_card = Algorithm.LocalSearch(G, Xcard, Ycard)

            _, _, grasp_cut_1, grasp_iters_1 = Algorithm.GRASP(G, iterations, 1, 0.9, 5)
            _, _, grasp_cut_2, grasp_iters_2 = Algorithm.GRASP(G, iterations, 2, 0.9, 5)           


            results.append([

                name, n, m,
                int(rand_cut), greedy_cut, semi_value,semi_card,
                local_iters_value, local_cut_value,
                local_iters_card, local_cut_card,
                grasp_iters_1, grasp_cut_1,
                grasp_iters_2, grasp_cut_2,
                knownbestdictionary.get(name.upper(), "")

            ])
    
    with open(output_csv , 'a' , newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow([
            "Problem", "", "",
            "Constructive Algorithm", "", "","",
            "Local Search", "", "", "",
            "GRASP", "", "", "",
            "Known best Solution or upper bound"
        ])

        writer.writerow([
            "Name", "|V| or n", "|E| or m",
            "Simple Randomized", "Greedy-1", "Semi-Greedy-1", "Semi-Greedy-2",
            "Local Search for Semi-Greedy-1", "", 
            "Local Search for Semi-Greedy-2", "", 
            "GRASP for Semi-Greedy-1", "", 
            "GRASP for Semi-Greedy-2", "", 
            "Known Best"
        ])

        writer.writerow([
            "", "", "",
            "", "", "", "", 
            "Number of Iterations", "Best Value",
            "Number of Iterations", "Best Value",
            "Number of Iterations", "Best Value",
            "Number of Iterations", "Best Value",
            ""
        ])


        writer.writerows(results)

known_best = {
    "G1": 12078,
    "G2": 12084,
    "G3": 12077,
    "G11": 627,
    "G12": 621,
    "G13": 645,
    "G14": 3187,
    "G15": 3169,
    "G16": 3172,
    "G22": 14123,
    "G23": 14129,
    "G24": 14131,
    "G32": 1560,
    "G33": 1537,
    "G34": 1541,
    "G35": 8000,
    "G36": 7996,
    "G37": 8009,
    "G43": 7027,
    "G44": 7022,
    "G45": 7020,
    "G48": 6000,
    "G49": 6000,
    "G50": 5988
}

run_all_input_files("graph_GRASP/set1", "2105168_final.csv" , known_best)

#957 - 1037
#1049 -


