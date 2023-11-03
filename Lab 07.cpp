#include <iostream>
#include <vector>
using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    for (int juego = 1; juego <= K; juego++) {
        int ganador, perdedor;
        if (habilidades[0] > habilidades[1]) {
            ganador = habilidades[0];
            perdedor = habilidades[1];
        } else {
            ganador = habilidades[1];
            perdedor = habilidades[0];
        }

        if (juego % (2 * N) == 0) {
            habilidades[0] = ganador;
            habilidades[1] = perdedor;
        } else {
            habilidades[1] = perdedor;
        }
    }

    return habilidades;
}

int main() {
    vector<int> habilidades = {30, 12};
    int N = 34;
    int K = 80;

    vector<int> resultado = Torneo(habilidades, N, K);

    cout << "Perdedor del juego " << K << ": " << resultado[1] << endl;
    cout << "Ganador del juego " << K << ": " << resultado[0] << endl;

    return 0;
}
