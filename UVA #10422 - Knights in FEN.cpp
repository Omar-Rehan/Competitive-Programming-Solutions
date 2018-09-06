#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second

struct chessBoard {
    char board[5][5];

    pair<int,int> getEmptyCell() {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (board[i][j] == ' ') return make_pair(i, j);
    }

    bool checkBoard() { // is the current board at the desired state?
        for (int i = 0; i < 4; i++)
            for (int j = (i > 1 ? i+1 : i); j < 5; j++)
                if (board[i][j] != '1') return false;

        for (int i = 1; i < 5; i++)
            for (int j = 0; j < (i > 2 ? i+1 : i); j++)
                if (board[i][j] != '0') return false;

        return board[2][2] == ' ';
    }
};

bool outOfBounds(int r, int c) {
    return (r < 0 || 4 < r || c < 0 || 4 < c);
}

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, 2, -2, 1, -1};
int BFS(chessBoard root) {
    queue<chessBoard> q;
    q.push(root);

    int dpth = 0, sz = 1;
    chessBoard crnt = root;
    for (; !q.empty() && dpth < 11; dpth++, sz = q.size()) {
        while (sz--) {
            crnt = q.front();
            q.pop();
            if (crnt.checkBoard()) return dpth;
            for (int i = 0; i < 8; i++) {
                pair<int,int> pos = crnt.getEmptyCell();
                int nxtRow = pos.row + dx[i];
                int nxtCol = pos.col + dy[i];
                
                if (!outOfBounds(nxtRow, nxtCol)) {
                    chessBoard tmp = crnt;
                    swap(tmp.board[pos.row][pos.col], tmp.board[nxtRow][nxtCol]);
                    q.push(tmp);
                }
            }
        }
    }
    return -1;
}

int main() {
    int t;
    string line;
    chessBoard cb;
    scanf("%d\n", &t);
    while (t--) {
        for (int i = 0; i < 5; i++) {
            getline(cin, line);
            for (int j = 0; j < 5; j++) {
                if (j >= line.length()) cb.board[i][j] = ' ';
                else cb.board[i][j] = line[j];
            }
        }

        int res = BFS(cb);
        if (res == -1) printf("Unsolvable in less than 11 move(s).\n");
        else printf("Solvable in %d move(s).\n", res);
    }
}
