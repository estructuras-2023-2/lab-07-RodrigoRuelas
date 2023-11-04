#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> Torneo(vector<int> H, int N, int K) {
    queue<int> cola;
    for (size_t i = 2; i < H.size(); ++i) {
        cola.push(H[i]);
    }

    int gameWon = 0;
    int currentPlayer = H[0];
    int challengerPlayer = H[1];

    vector<int> result(2);
    for (int game = 1; game <= K; ++game) {
        if (currentPlayer > challengerPlayer) {
            gameWon++;
        } else {
            gameWon = 1;
            swap(currentPlayer, challengerPlayer);
        }
        
        result = {challengerPlayer, currentPlayer};
        cola.push(challengerPlayer);

        if (gameWon == N) {
            cola.push(currentPlayer);
            currentPlayer = cola.front();
            cola.pop();
            gameWon = 0;
        }

        challengerPlayer = cola.front();
        cola.pop();
    }

    return result;
}

void imprimirResultado(const vector<int>& R, int K) {
    cout << "Perdedor del juego " << K << ": " << R[0] << " Ganador del juego " << K << ": " << R[1] << endl;
}

int main() {
    // Entradas
    vector<int> H1 = {1, 2, 3};
    int N1 = 2;
    int K1 = 2;

    vector<int> H2 = {49, 24, 26, 12, 5, 33, 25, 30, 35, 41, 46, 23, 21, 3, 38, 43, 11, 19, 34, 29, 20, 32, 39, 7, 50};
    int N2 = 10;
    int K2 = 399;

    vector<int> H3 = {1, 2, 3};
    int N3 = 2;
    int K3 = 4;

    vector<int> H4 = {30, 12};
    int N4 = 34;
    int K4 = 80;

    // Resultados
    vector<int> R1 = Torneo(H1, N1, K1);
    vector<int> R2 = Torneo(H2, N2, K2);
    vector<int> R3 = Torneo(H3, N3, K3);
    vector<int> R4 = Torneo(H4, N4, K4);

    // Salidas
    imprimirResultado(R1, K1);
    imprimirResultado(R2, K2);
    imprimirResultado(R3, K3);
    imprimirResultado(R4, K4);

    return 0;
}



