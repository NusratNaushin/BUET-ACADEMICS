from MAXCUT.Edge import Edge

class Graph:
    def __init__(self , n , m):
        self.n = n
        self.m = m
        self.edges = []
    
    def add_edge(self , u , v , w):
        self.edges.append(Edge(u,v,w))
        self.edges.append(Edge(v , u , w))