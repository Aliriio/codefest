n=int(input())

tablero=[]

for i in range(n):

    a=[]

    for j in range(n):

        a.append(0)

    tablero.append(a)



entrada=input().split(" ")

for i in range(len(entrada)):

    entrada[i] = int(entrada[i])

cor_X = entrada[0]

cor_Y = entrada[1]

potencia = entrada[2]

 

#Reemplazar la posicion i,j con potencia

tablero[cor_X][cor_Y] = potencia

 

for x in range(n):

    for y in range(n):

        distanciaX = abs(cor_X - x)

        distanciaY = abs(cor_Y - y)

        distancia = max([distanciaX, distanciaY])

        if(potencia > distancia):

            tablero[x][y] = potencia - distancia

 


for i in range(n):

    for j in range(n):

        if j == n-1:

            print(tablero[i][j], end="")

        else:

            print(tablero[i][j], end=" ")

    print()