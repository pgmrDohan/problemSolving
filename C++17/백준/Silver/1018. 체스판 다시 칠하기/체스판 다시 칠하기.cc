#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int drawChessboard(vector<string>& board, int x, int y);

int main() {
    int M, N;
    cin >> M >> N;
    vector<string> board(M);
    for (int i = 0; i < M; i++) {
        cin >> board[i];
    }
    vector<int> drawCounts;

    for (int i = 0; i < M - 7; i++) {
        for (int j = 0; j < N - 7; j++) {
            drawCounts.push_back(drawChessboard(board, j, i));
        }
    }
    sort(drawCounts.begin(), drawCounts.end());
    cout << drawCounts[0];
    return 0;
}

int drawChessboard(vector<string>& board, int x, int y) {
    int wcnt = 0;
    int bcnt = 0;
    bool white = true;
    bool black = false;

    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            int nowC = board[i][j] == 'W' ? true : false;
            if (nowC != white) wcnt++;
            if (nowC != black) bcnt++;
            white = !white;
            black = !black;
        }
        white = !white;
        black = !black;
    }
    return wcnt < bcnt ? wcnt : bcnt;
}