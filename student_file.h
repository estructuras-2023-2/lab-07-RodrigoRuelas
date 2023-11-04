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
