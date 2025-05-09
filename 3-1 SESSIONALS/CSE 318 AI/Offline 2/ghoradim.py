import random
class Edge:
    def __init__(self , u , v , w):
        self.u = u
        self.v = v
        self.w = w

class Graph:
    def __init__(self , n , m):
        self.n = n
        self.m = m
        self.edges = []
        self.alpha = 0.9
        self.adj = {}
    
    def add_edge(self , u , v , w):
        self.edges.append(Edge(u , v , w))
        self.edges.append(Edge(v , u , w))

        if u not in self.adj:
            self.adj[u] = []
        if v not in self.adj:
            self.adj[v] = []
        
        self.adj[u].append((v, w))
        self.adj[v].append((u, w))


class Algorithm:
    def Greedy(G):
        XnodePartitions = set()
        YnodePartitions = set()
        partiton_members = set()



        collect_all_unique_edge = []

        already_visited_edges = set()


        for edge in G.edges:
            key = tuple(sorted((edge.u , edge.v)))
            if key not in already_visited_edges:
                collect_all_unique_edge.append((edge.u , edge.v , edge.w))
                already_visited_edges.add(key)

        
        

        edge_with_max_weight = max(collect_all_unique_edge , key = lambda edge:edge[2])


        u , v , w =edge_with_max_weight


        XnodePartitions.add(u)
        YnodePartitions.add(v)

        partiton_members.update([u,v])

        for node in range(1 , G.n+1):
            if node in partiton_members:
                continue
                
            wx = 0
            wy = 0

            for edge in G.edges:
                if edge.u == node:
                    if edge.v in XnodePartitions:
                        wx += edge.w
                    elif edge.v in YnodePartitions:
                        wy += edge.w
                elif edge.v == node:
                    if edge.u in XnodePartitions:
                        wx += edge.w
                    elif edge.u in YnodePartitions:
                        wy += edge.w

            if wy > wx:
                XnodePartitions.add(node)
            else:
                YnodePartitions.add(node)
                
            partiton_members.add(node)

           
                    
        cut_weight = 0
        # for edge in G.edges:
        #     if(edge.u in XnodePartitions and edge.v in YnodePartitions) or (edge.u in YnodePartitions and edge.v in XnodePartitions):
        #         cut_weight += edge.w
        # cut_weight = cut_weight//2

        for u, v, w in collect_all_unique_edge:
           if (u in XnodePartitions and v in YnodePartitions) or (u in YnodePartitions and v in XnodePartitions):
                cut_weight += w


        return XnodePartitions , YnodePartitions , cut_weight


    def RandomizedMaxCut(G , iterations):
        totalCutWeight=0

        nodes = set()

        for edge in G.edges:
            nodes.add(edge.u)
            nodes.add(edge.v)


        for _ in range(iterations):
            X=set()
            Y=set()
            for v in nodes:
                if random.random() < 0.5:
                    Y.add(v)
                else:
                    X.add(v)
                

            visited_nodes = set()
            cutWeight = 0

            for edge in G.edges:
                key = tuple(sorted((edge.u , edge.v)))
                if key in visited_nodes:
                    continue
                if (edge.u in X and edge.v in Y) or (edge.v in X and edge.u in Y):
                    cutWeight += edge.w
                visited_nodes.add(key)
        
            totalCutWeight += cutWeight

        
        avgCutWeight = totalCutWeight/iterations

        return avgCutWeight 
    
    def setAlpha(self, alpha):
        self.alpha = alpha
    def CalculateSigma(G, candidateNodes , X , Y):

        # nodes = set()

        # for edge in G.edges:
        #     nodes.add(edge.u)
        #     nodes.add(edge.v)

        #print("inside calculate sigma")
        
        sigmax={}
        sigmay={}
        greedyFnValue={}

        for node in candidateNodes:
            sx=0
            sy=0
            for neighbour , w in G.adj.get(node, []):
                if neighbour in X:
                    sx += w
                elif neighbour in Y:
                    sy += w
            sigmax[node] = sx
            sigmay[node] = sy
            greedyFnValue[node] = max(sx , sy)

        return sigmax , sigmay , greedyFnValue

        
        

    def SemiGreedy_CardinalityBasedRCL(G , k):
        
        #print("inside semigreedy")
        best_cut = 0
        nodes = set()

        for edge in G.edges:
            nodes.add(edge.u)
            nodes.add(edge.v)

        collect_all_unique_edge = []

        already_visited_edges = set()


        for edge in G.edges:
            key = tuple(sorted((edge.u , edge.v)))
            if key not in already_visited_edges:
                collect_all_unique_edge.append((edge.u , edge.v , edge.w))
                already_visited_edges.add(key)
        
        u , v ,_ = random.choice(collect_all_unique_edge)

        XnodePartitions = {u}
        YnodePartitions = {v}

        assigned_to_either_partitions = {u , v}

        while len(assigned_to_either_partitions) < len(nodes):
            candies = list(nodes - assigned_to_either_partitions)
            sigmax , sigmay , greedyFnValue = Algorithm.CalculateSigma(G , candies , XnodePartitions , YnodePartitions)


            sorted_candidates = sorted(greedyFnValue.items(), key=lambda item: item[1], reverse=True)
            topK = min(k , len(sorted_candidates))  
            topKcandies = sorted_candidates[:topK]        

            RCL = []
            for node, _ in topKcandies:
                RCL.append(node)

            randomly_chosen_vertex_from_RCL = random.choice(RCL)

            if sigmax[randomly_chosen_vertex_from_RCL] > sigmay[randomly_chosen_vertex_from_RCL]:
                YnodePartitions.add(randomly_chosen_vertex_from_RCL)
            else:
                XnodePartitions.add(randomly_chosen_vertex_from_RCL)
            
            assigned_to_either_partitions.add(randomly_chosen_vertex_from_RCL)
            #print("assigning RCL")
        

        seen = set()
        cut = 0

        for edge in G.edges:
            key = tuple(sorted((edge.u , edge.v)))
            if key in seen:
                continue
            if (edge.u in XnodePartitions and edge.v in YnodePartitions) or (edge.v in XnodePartitions and edge.u in YnodePartitions):
                cut += edge.w
            seen.add(key)

        return XnodePartitions , YnodePartitions , cut








    def ValueBasedRCL(greedyFnvalue , sigmax , sigmay , alpha):

        # nodes = set()

        # for edge in G.edges:
        #     nodes.add(edge.u)
        #     nodes.add(edge.v)

        #Algorithm.setAlpha(alpha)

        wmin = min(min(sigmax.values()), min(sigmay.values()))
        wmax = max(max(sigmax.values()), max(sigmay.values()))



        CutOffMu = wmin +alpha*(wmax - wmin)

        resultingCandies = []

        for node in greedyFnvalue:
            if greedyFnvalue[node] >= CutOffMu :
                resultingCandies.append(node)
            
        return resultingCandies

    
    def SemiGreedyValueBased(G , alpha):
        best_cut = 0
        nodes = set()
        for edge in G.edges:
            nodes.add(edge.u)
            nodes.add(edge.v)

        collect_all_unique_edge = []

        already_visited_edges = set()


        for edge in G.edges:
            key = tuple(sorted((edge.u , edge.v)))
            if key not in already_visited_edges:
                collect_all_unique_edge.append((edge.u , edge.v , edge.w))
                already_visited_edges.add(key)
        
        firstu ,firstv , _ = random.choice(list(collect_all_unique_edge))

        XnodePartitions = {firstu}
        YnodePartitions = {firstv}

        assigned_to_either_partiton = {firstu , firstv}

        while len(assigned_to_either_partiton) < len(nodes):
            candies = list(nodes - assigned_to_either_partiton)
            sigmax , sigmay , greedyFnValue = Algorithm.CalculateSigma(G , candies , XnodePartitions , YnodePartitions)
            RCL = Algorithm.ValueBasedRCL( greedyFnValue , sigmax , sigmay , alpha)

            if not RCL:
                RCL = candies 
            
            randomly_selected_vertex_from_RCL = random.choice(RCL)


            if sigmax[randomly_selected_vertex_from_RCL] > sigmay[randomly_selected_vertex_from_RCL]:
                YnodePartitions.add(randomly_selected_vertex_from_RCL)
            else:
                XnodePartitions.add(randomly_selected_vertex_from_RCL)


            assigned_to_either_partiton.add(randomly_selected_vertex_from_RCL)

        seen = set()
        cut = 0

        for edge in G.edges:
            key = tuple(sorted((edge.u , edge.v)))
            if key in seen:
                continue
            if (edge.u in XnodePartitions and edge.v in YnodePartitions) or (edge.v in XnodePartitions and edge.u in YnodePartitions):
                cut += edge.w
            seen.add(key)

        return XnodePartitions , YnodePartitions , cut



        
        
        
    


def main():

    # graph = Graph(2 , 1)
    # graph.add_edge(1 , 2 , 3)

    
    filename="graph_GRASP/set1/g4.rud"

    with open(filename , 'r') as f:
        n , m = map(int , f.readline().split())
        graph = Graph(n , m)

        for _ in range(m):
            u , v , w = map(int, f.readline().split())
            graph.add_edge(u,v,w)
           # print("adding edge " , u , v)

    X, Y, cut_weight = Algorithm.Greedy(graph)
    print("\nGreedy Partition:")
    print("Set X:", sorted(X))
    print("Set Y:", sorted(Y))
    print("Cut Weight:", cut_weight)

    avg_cut = Algorithm.RandomizedMaxCut(graph, 100)
    print(f"\nRandomized Max-Cut (avg over 100 runs): {avg_cut:.2f}")

    Xsemi, Ysemi, cut_semi = Algorithm.SemiGreedyValueBased(graph, 0.9)
    print(f"\nSemi-Greedy Value-Based (a=0.9): Cut = {cut_semi}")

    Xcard, Ycard, cut_card = Algorithm.SemiGreedy_CardinalityBasedRCL(graph, k=5)
    print(f"\nSemi-Greedy Cardinality-Based (k=5): Cut = {cut_card}")



main()