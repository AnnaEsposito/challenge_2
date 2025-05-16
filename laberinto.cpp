#include <iostream>
#include <vector>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::random_device, std::mt19937
#include <queue>     // Para usar colas, que son esenciales en la implementación de BFS 
#include <tuple>     // Para std::pair y std::tuple
#include <cstdlib>   // Para std::shuffle

using namespace std;

// Declaro las funciones a utilizar
void laberinto(int alto, int ancho);
void crearCamino(int x, int y, vector<vector<char>>& matriz, int alto, int ancho, pair<int, int> salida);
void imprimirLaberinto(const vector<vector<char>>& matriz);
bool esValido(int x, int y, int alto, int ancho);

// Función para resolver el laberinto utilizando BFS y marcar el camino correcto
bool resolverLaberinto(int alto, int ancho, pair<int, int> inicio, pair<int, int> fin, vector<vector<char>>& matriz) {
    vector<vector<bool>> visitado(alto, vector<bool>(ancho, false)); // vector de nodos ya visitados
    vector<vector<pair<int, int>>> previo(alto, vector<pair<int, int>>(ancho, {-1, -1})); // matriz de coordenadas previas

    queue<pair<int, int>> cola; 
    cola.push(inicio);
    visitado[inicio.first][inicio.second] = true;

    vector<pair<int, int>> direcciones = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!cola.empty()) {
        int x, y;
        tie(x, y) = cola.front();
        cola.pop();

        if (x == fin.first && y == fin.second) {
            // Reconstruir el camino desde el final hasta el inicio
            pair<int, int> actual = fin;
            while (actual != inicio) {
                matriz[actual.first][actual.second] = 'C'; // Marcar el camino correcto 
                actual = previo[actual.first][actual.second];
            }
            matriz[inicio.first][inicio.second] = 'E'; // Asegurar que el inicio se mantenga marcado
            matriz[fin.first][fin.second] = 'S'; // Asegurar que la salida se mantenga marcada
            return true; // Encontró el camino
        }

        for (const pair<int, int>& dir : direcciones) {
            int nx = x + dir.first, ny = y + dir.second;
            if (esValido(nx, ny, alto, ancho) && matriz[nx][ny] != '#' && !visitado[nx][ny]) {
                cola.push({nx, ny});
                visitado[nx][ny] = true;
                previo[nx][ny] = {x, y}; // Guardar la coordenada previa
            }
        }
    }

    return false; // No encontró el camino
}


// Función para crear el laberinto
void laberinto(int alto, int ancho) {
    vector<vector<char>> matriz(alto, vector<char>(ancho, '#'));

    pair<int, int> inicio = {1, 1};
    pair<int, int> fin = {alto - 2, ancho - 2};
    matriz[inicio.first][inicio.second] = 'E';

    // Llamar a crearCamino con la posición de inicio, tamaño del laberinto y posición de salida
    crearCamino(inicio.first, inicio.second, matriz, alto, ancho, fin);

    // Eliminar las paredes adyacentes a la salida
    matriz[fin.first][fin.second] = ' '; // Limpiar la celda de salida
    if (fin.first > 0) matriz[fin.first - 1][fin.second] = ' '; // Arriba de la salida
    if (fin.first < alto - 1) matriz[fin.first + 1][fin.second] = ' '; // Abajo de la salida
    if (fin.second > 0) matriz[fin.first][fin.second - 1] = ' '; // Izquierda de la salida
    if (fin.second < ancho - 1) matriz[fin.first][fin.second + 1] = ' '; // Derecha de la salida

    // Intentar resolver el laberinto
    if (resolverLaberinto(alto, ancho, inicio, fin, matriz)) {
        cout << "\nSe encontró una solución para el laberinto.\n";
    } else {
        cout << "\nNo se encontró una solución para el laberinto.\n";
    }

    // Imprimir el laberinto después de resolverlo
    cout << "\nLaberinto después de resolver:\n";
    imprimirLaberinto(matriz);
}

// Inicializar la función crear camino
// crearCamino recibe la matriz por referencia para modificarla directamente.
void crearCamino(int x, int y, vector<vector<char>>& matriz, int alto, int ancho, pair<int, int> salida) {
    static const vector<pair<int, int>> direcciones = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    matriz[x][y] = ' ';

    // Generador de números aleatorios
    random_device rd;
    mt19937 g(rd());

    // Desordenar aleatoriamente las direcciones
    vector<pair<int, int>> shuffledDirecciones = direcciones;
    shuffle(shuffledDirecciones.begin(), shuffledDirecciones.end(), g);

    for (const pair<int, int>& dir : shuffledDirecciones) {
        int nx = x + dir.first * 2, ny = y + dir.second * 2;
        // Verificar si la nueva posición está dentro de los límites y es un muro
        if (esValido(nx, ny, alto, ancho) && matriz[nx][ny] == '#') {
            matriz[nx - dir.first][ny - dir.second] = ' '; // Abrir el camino intermedio
            crearCamino(nx, ny, matriz, alto, ancho, salida); // Llamada recursiva

            
        }
    }
}

bool esValido(int x, int y, int alto, int ancho) {
    return x > 0 && x < alto - 1 && y > 0 && y < ancho - 1;
}

// Función para imprimir el laberinto
void imprimirLaberinto(const vector<vector<char>>& matriz) {
    for (const auto& fila : matriz) {
        for (char celda : fila) {
            cout << celda << ' ';
        }
        cout << endl;
    }
}


int main() {
    int ancho, alto;
    cout << "Ingrese el ancho del laberinto: ";
    cin >> ancho;

    cout << "Ingrese el alto del laberinto: ";
    cin >> alto;

    // Llamar a la función laberinto 
    laberinto(alto, ancho);

    return 0;
}

