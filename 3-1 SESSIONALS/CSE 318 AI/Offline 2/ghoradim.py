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
    
    def add_edge(self , u , v , w):
        self.edges.append(Edge(u , v , w))
        self.edges.append(Edge(v , u , w))


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
                    X.add(v)
                else:
                    Y.add(v)
                

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

    X, Y, cut_weight = Algorithm.Greedy(graph)
    print("\nGreedy Partition:")
    print("Set X:", sorted(X))
    print("Set Y:", sorted(Y))
    print("Cut Weight:", cut_weight)

    avg_cut = Algorithm.RandomizedMaxCut(graph, 100)
    print(f"\nRandomized Max-Cut (avg over 100 runs): {avg_cut:.2f}")


main()