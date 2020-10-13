#This function utilizes Dijkstra's algorithm to find the shortest path from the chosen vertex to the others.
def dijkstra(matrix, nRows, nColumns, nVertex):
    vertex = nVertex - 1
    listClosed = []
    listaVertex = []
    listDistance = []
    origin = -1
    estimation = float("inf")
    for i in range(nRows):
        if (i == vertex):
            listDistance.append(0)
        else:
            listDistance.append(estimation)
        listClosed.append(0)
    for i in range(nRows):
        min0 = float("inf")
        for j in range(nRows):
            if (listDistance[j] < min0 and listClosed[j] == 0):
                min0 = listDistance[j]
                origin = j
        listClosed[origin] = 1
        for j in range(nColumns):
            if (matrix[origin][j] != 0 and matrix[origin][j] + listDistance[origin] < listDistance[j]):
                listDistance[j] = matrix[origin][j] + listDistance[origin]
    return listDistance


# This function prints the distance from the inital vertex to the others
def printDijkstra(list):
    nDist = len(list)
    for i in range(nDist):
        print("The distance to the vertex " + str(i + 1) + " is: " + str(list[i]))



#We start with  the adjacency matrix of a weighted graph.
adjacencyMatrix = [[0, 10, 5, 0, 0, 0], [0, 0, 0, 1, 0, 0], [0, 3, 0, 8, 2, 0], [0, 0, 0, 0, 4, 4], [0, 0, 0, 0, 0, 6], [0, 0, 0, 0, 0, 0]]
originVertex = 1  # Here you can chose the origin vertex (value >=1)
nRows=len(adjacencyMatrix[0])
nColumns=len(adjacencyMatrix)
#Here we get the shortest paths from the origin vertex utilizing Dijkstra's Algorithm
finalDijkstra = dijkstra(adjacencyMatrix, nRows, nColumns, originVertex)
# Now we just print the distances from the chosen vertex to another.
printDijkstra(finalDijkstra)
