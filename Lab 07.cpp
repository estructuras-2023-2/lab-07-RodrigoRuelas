#include <iostream>
#include <vector>
using namespace std;

vector<int> Torneo(std::vector<int> habilidades, int N, int K) {
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

int main()
{
    cout<<"Hello World";

    return 0;
}
