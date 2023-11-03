#include <iostream>
#include <vector>
using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    int ganador, perdedor;

    for (int juego = 1; juego <= K; juego++) {
        if (habilidades[0] > habilidades[1]) {
            ganador = habilidades[0];
            perdedor = habilidades[1];
        } else {
            ganador = habilidades[1];
            perdedor = habilidades[0];
        }

        if (juego % (2 * N) == 0) {
            habilidades.push_back(ganador);
            habilidades.erase(habilidades.begin(), habilidades.begin() + 2);
        } else {
            habilidades.push_back(perdedor);
            habilidades.erase(habilidades.begin(), habilidades.begin() + 1);
        }
    }

    return {perdedor, ganador};
}

void imprimirResultado(const vector<int>& resultado, int K) {
    cout << "Perdedor del juego " << K << ": " << resultado[0] << " Ganador del juego " << K << ": " << resultado[1] << endl;
}

int main() {
    // Entradas
    vector<int> habilidades1 = {1, 2, 3};
    int N1 = 2;
    int K1 = 2;

    vector<int> habilidades2 = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
    int N2 = 10;
    int K2 = 399;

    vector<int> habilidades3 = {1, 2, 3};
    int N3 = 2;
    int K3 = 4;

    vector<int> habilidades4 = {30, 12};
    int N4 = 34;
    int K4 = 80;

    // Resultados
    vector<int> resultado1 = Torneo(habilidades1, N1, K1);
    vector<int> resultado2 = Torneo(habilidades2, N2, K2);
    vector<int> resultado3 = Torneo(habilidades3, N3, K3);
    vector<int> resultado4 = Torneo(habilidades4, N4, K4);

    // Salidas
    imprimirResultado(resultado1, K1);
    imprimirResultado(resultado2, K2);
    imprimirResultado(resultado3, K3);
    imprimirResultado(resultado4, K4);

    return 0;
}

