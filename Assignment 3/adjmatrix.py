import math
class Node:
    def __init__(self, label = None, dist=None):
        #Distance from source
        self.label = label
        self.isVisited = False
        self.distance = dist
        self.neigbors = []
        self.parent = None
graph = []
def createGraph():
    global graph
    adj_matrix = []
    #Make 6 nodes
    for i in range(1, 7):
        #Create new node labeling by the index
        newNode = Node(i)
        graph.append(newNode)
    #Distance between nodes
    edges = {(1, 2): 4,
             (1, 3): 1,
             (1, 4): 5,
             (1, 5): 8,
             (1, 6): 10,
             (3, 2): 2,
             (4, 5): 2,
             (5, 6): 1}
     #Initialize the adjacency matrix
    for i in range(1, 7):
         adj_matrix.append([])
         for j in range(1, 7):
             adj_matrix[i-1].append(-1)
                      
    for nodes, value in edges.items():
        nodeA, nodeB = nodes
        adj_matrix[nodeA - 1][nodeB - 1] = value
        adj_matrix[nodeB - 1][nodeA - 1] = value


    neighbors = {}
    for nodeA, nodeB in edges.keys():
        if nodeA not in neighbors:
            neighbors[nodeA] = []
        if nodeB not in neighbors:
            neighbors[nodeB] = []
        if graph[nodeB - 1] not in neighbors[nodeA]:
            neighbors[nodeA].append(graph[nodeB - 1])
        if graph[nodeA - 1] not in neighbors[nodeB]:
            neighbors[nodeB].append(graph[nodeA - 1])
    return (graph, edges, neighbors, adj_matrix)


def dijkstra(graph_info, goal):
    """Graph info include: list of nodes, distances between nodes, and neighbor list"""
    graph, edges, neighbors, adj_matrix = graph_info
    #Initialize node's value: source node = 0, every other node = inf
    for node in graph:
        #if is source node
        if node.label == 1:
            node.distance = 0
            node.parent = -1
        else:
            node.distance = math.inf

    for node in graph:
        if node.label == goal:
            return adj_matrix
            
        if not node.isVisited:
            #Calculate the distance with node's neighbors
            #  edges[(node, neighbor)] returns distance between
            #  the current node and the neighbor
            for neighbor in neighbors[node.label]:
                try:
                    dist_curNode_toNeighbor = edges[(node.label, neighbor.label)]
                except KeyError:
                    dist_curNode_toNeighbor = edges[(neighbor.label, node.label)]

                dist_from_src = node.distance + dist_curNode_toNeighbor

                if dist_from_src < neighbor.distance:
                    neighbor.distance = dist_from_src
                    adj_matrix[node.label - 1][neighbor.label - 1] = neighbor.distance
                    #Keep track the parent--which node leads here
                    # --to backtrace the shortest path later
                    neighbor.parent = node

            # When done evaluating the neighbor, mark the current
            # node as visited
            node.isVisited = True
    return adj_matrix

def printShortestPath(node):
    if node.parent == -1:
        print("Dist from src to ", node.label, ": ", node.distance)
    else:
        printShortestPath(node.parent)
        print("Dist from src to ", node.label, ": ", node.distance)
graph_info = createGraph()
adj_matrix = dijkstra(graph_info, -1)
print("Adjacency matrix: ", adj_matrix)
print("The shortest path to last node: ")
printShortestPath(graph[len(graph)-1])

