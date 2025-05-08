from MAXCUT.Graph import Graph

def main():

    graph = Graph(2 , 1)
    graph.add_edge(1 , 2 , 3)
    print(f"{graph.u} -- {graph.v} (weight {graph.w})")

    print("hello")


main()