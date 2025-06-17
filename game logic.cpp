#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}


void printBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << '|';
        }
        cout << endl;
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE - 1; ++j) {
                cout << "-----";
            }
            cout << endl;
        }
    }
}

bool makeMove(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
        return false; // Invalid move
    }
    board[row][col] = currentPlayer;
    return true;
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }
    return false;
}

void playGame() {
    initializeBoard();
    int moves = 0;
    while (moves < SIZE * SIZE) {
        printBoard();
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (makeMove(row - 1, col - 1)) {
            if (checkWin()) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                return;
            }
            switchPlayer();
            moves++;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    printBoard();
    cout << "It's a draw!" << endl;
}




int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    playGame();
    cout << "Thank you for playing!" << endl;
    cout << "Press any key to exit." << endl;
    cin.ignore();
    cin.get();
    cout << "Goodbye!" << endl;

    // Return 0 to indicate successful execution
        
    
    return 0;
}