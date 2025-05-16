import random
from collections import deque

# Función para imprimir el laberinto
def imprimir_laberinto(matriz):
    for fila in matriz:
        print(" ".join(fila))
    print()

# Función para crear el laberinto
def crear_laberinto(alto, ancho):
    matriz = [["#" for _ in range(ancho)] for _ in range(alto)]
    inicio = (1, 1)
    salida = (alto - 2, ancho - 2)
    matriz[inicio[0]][inicio[1]] = "E"

    direcciones = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    crear_camino(inicio[0], inicio[1], matriz, alto, ancho, salida, direcciones)
    matriz[salida[0]][salida[1]] = "S"
    return matriz, inicio, salida

# Función recursiva para crear caminos
def crear_camino(x, y, matriz, alto, ancho, salida, direcciones):
    random.shuffle(direcciones)
    for dx, dy in direcciones:
        nx, ny = x + dx * 2, y + dy * 2
        if 0 < nx < alto - 1 and 0 < ny < ancho - 1 and matriz[nx][ny] == "#":
            matriz[x + dx][y + dy] = " "  # Limpia el espacio intermedio
            matriz[nx][ny] = " "  # Limpia el nuevo espacio
            crear_camino(nx, ny, matriz, alto, ancho, salida, direcciones)

# Función para resolver el laberinto usando BFS
def resolver_laberinto(matriz, inicio, salida):
    alto, ancho = len(matriz), len(matriz[0])
    visitado = [[False for _ in range(ancho)] for _ in range(alto)]
    previo = [[None for _ in range(ancho)] for _ in range(alto)]
    cola = deque([inicio])
    visitado[inicio[0]][inicio[1]] = True

    while cola:
        x, y = cola.popleft()

        if (x, y) == salida:
            # Reconstruir el camino
            while (x, y) != inicio:
                matriz[x][y] = "C"
                x, y = previo[x][y]
            matriz[inicio[0]][inicio[1]] = "E"
            matriz[salida[0]][salida[1]] = "S"
            return True

        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < alto and 0 <= ny < ancho and not visitado[nx][ny] and matriz[nx][ny] != "#":
                visitado[nx][ny] = True
                previo[nx][ny] = (x, y)
                cola.append((nx, ny))

    return False

# Función principal para ejecutar el laberinto
if __name__ == "__main__":
    ancho = int(input("Ingrese el ancho del laberinto: "))
    alto = int(input("Ingrese el alto del laberinto: "))
    matriz, inicio, salida = crear_laberinto(alto, ancho)
    imprimir_laberinto(matriz)

    if resolver_laberinto(matriz, inicio, salida):
        print("\nSe encontró una solución para el laberinto:\n")
    else:
        print("\nNo se encontró una solución para el laberinto.\n")
    imprimir_laberinto(matriz)

