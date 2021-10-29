n = int(input())
matriz = []
for i in range(n):
    linha = input().split()
    linha = list(map(int, linha))
    matriz.append(linha)



for i in range(len(matriz)):
    branca = 0
    preta = 0
    for j in range(len(matriz[i])):
        if matriz[i][j] == 1 or matriz[i][j] == 0:
            continue
        else:
            if matriz[i-1][j] == 1:
                preta += 1
            else:
                branca += 1
            if matriz[i-1][j-1] == 1:
                preta += 1
            else:
                branca += 1
            if matriz[i][j-1] == 1:
                preta += 1
            else:
                branca += 1
        if branca > preta:
            matriz[i][j] = 1
        else:
            matriz[i][j] = 0
        preta = 0
        branca = 0

print(matriz[n-1][n-1])