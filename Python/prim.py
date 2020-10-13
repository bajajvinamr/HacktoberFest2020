def create_matrix(n_lines, n_columns, value):  # Create a matrix
    matrix = []
    for i in range(n_lines):
        line = []
        for j in range(n_columns):
            line.append(value)
        matrix.append(line)
    return matrix

def prim(adjacency_matrix): # Function that receives a adjacency matrix and return the minimal spanning tree's adjacency matrix
    vertexes = [0]
    column = 0
    line = 0
    spanning_tree = create_matrix(len(adjacency_matrix), len(adjacency_matrix[0]), 0)

    for k in range(len(adjacency_matrix)-1):
        min1 = 0
        for i in vertexes:
            for j in range(len(adjacency_matrix[i])):
                if j not in vertexes:
                    if min1 == 0 and adjacency_matrix[i][j] != 0:
                        min1 = adjacency_matrix[i][j]
                        line = i
                        column = j
                    elif adjacency_matrix[i][j] < min1 and adjacency_matrix[i][j] != 0:
                        min1 = adjacency_matrix[i][j]
                        line = i
                        column = j

        spanning_tree[line][column] = min1
        spanning_tree[column][line] = min1
        vertexes.append(column)
    return spanning_tree


matrix = [[0, 10, 0, 0, 0, 8], [0, 0, 0, 2, 0, 0], [0, 1, 0, 0, 0, 0], [0, 0, -2, 0, 0, 0], [0, -4, 0, -1, 0, 0], [0, 0, 0, 0, 1, 0]]
spanning_tree = prim(matrix)

for line in spanning_tree:
    line_result = ""
    for j in line:
        line_result += str(j)+","
    line_result = line_result[:-1]
    print(line_result)



