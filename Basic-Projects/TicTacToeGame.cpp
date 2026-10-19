// Project: Tic-Tac-Toe Game
// Language: C++
// Description: Two-player console game.

#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }

        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
}

bool checkWinner(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player) {
            return true;
        }

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player) {
            return true;
        }
    }

    return (board[0][0] == player &&
            board[1][1] == player &&
            board[2][2] == player) ||
           (board[0][2] == player &&
            board[1][1] == player &&
            board[2][0] == player);
}

int main() {
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    char player = 'X';
    int move;
    int turns = 0;

    while (turns < 9) {
        displayBoard(board);

        cout << "Player " << player << ", choose a cell (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid cell.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already occupied.\n";
            continue;
        }

        board[row][col] = player;
        turns++;

        if (checkWinner(board, player)) {
            displayBoard(board);
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    displayBoard(board);
    cout << "The game is a draw.\n";

    return 0;
}
