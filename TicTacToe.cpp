// Lab 1: Review
#include <iostream>

using namespace std;

const int NUM_ROWS = 3;
const int NUM_COLUMNS = 3;
const int MAX_TURNS = 9;

class TicTacToeBoard {
    private:
        char gameBoard[NUM_ROWS][NUM_COLUMNS];

    public:
        TicTacToeBoard();
        int printBoard();
        int xPlay();
        int oPlay();
        int determineWinner();
        int spaceVerification(int, int);
        int inputValidation(int);
};

TicTacToeBoard::TicTacToeBoard() {
    for(int x = 0; x < NUM_ROWS; x++) {
        for(int y = 0; y < NUM_COLUMNS; y++) {
            gameBoard[x][y] = '*';
        }
    }
}

int TicTacToeBoard::printBoard() {
    cout << "\n   1  2  3\n";
    for(int x = 0; x < NUM_ROWS; x++) {
        cout << x + 1 << " ";
        for(int y = 0; y < NUM_COLUMNS; y++) {
            cout << "[" << gameBoard[x][y] << "]";
        }
        cout << endl;
    }
    cout << "\n";

    return 0;
}

int TicTacToeBoard::xPlay() {
    int row = 0, col = 0;

    cout << "It's player X\'s turn.";
    
    while(spaceVerification(row,col)) {
        cout << "\nType in row... ";
        cin >> row;
        while(inputValidation(row)) {
            cout << "\nType in row... ";
            cin >> row;
        }

        cout << "Type in column... ";
        cin >> col;
        while(inputValidation(col)) {
            cout << "\nType in column... ";
            cin >> col;
        }
    }

    row--;
    col--;
    gameBoard[row][col] = 'X';
    return 0;
}

int TicTacToeBoard::oPlay() {
    int row = 0, col = 0;

    cout << "It's player O\'s turn.";
    
    while(spaceVerification(row,col)) {
        cout << "\nType in row... ";
        cin >> row;
        while(inputValidation(row)) {
            cout << "\nType in row... ";
            cin >> row;
        }

        cout << "Type in column... ";
        cin >> col;
        while(inputValidation(col)) {
            cout << "\nType in column... ";
            cin >> col;
        }
    }

    row--;
    col--;
    gameBoard[row][col] = 'O';
    return 0;
}

int TicTacToeBoard::determineWinner() {
    int winFactor = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(gameBoard[i][j] == 'X') {
                winFactor++;
            } else if (gameBoard[i][j] == 'O') {
                winFactor--;
            }

            if(winFactor == 3) {
                return 1;
            } else if(winFactor == -3) {
                return 2;
            }
        }
        winFactor = 0;
    }

    winFactor = 0;

    for(int k = 0; k < 3; k++) {
        for(int l = 0; l < 3; l++) {
            if(gameBoard[l][k] == 'X') {
                winFactor++;
            } else if (gameBoard[l][k] == 'O') {
                winFactor--;
            }

            if(winFactor == 3) {
                return 1;
            } else if(winFactor == -3) {
                return 2;
            }
        }
        winFactor = 0;
    }

    winFactor = 0;

    for(int m = 0; m < 3; m++) {
        if(gameBoard[m][m] == 'X') {
            winFactor++;
        } else if (gameBoard[m][m] == 'O') {
            winFactor--;
        }

        if(winFactor == 3) {
            return 1;
        } else if(winFactor == -3) {
            return 2;
        }
    }

    winFactor = 0;

    for(int n = 2, o = 0; n > -1; n--, o++) {
        if(gameBoard[n][o] == 'X') {
            winFactor++;
        } else if (gameBoard[n][o] == 'O') {
            winFactor--;
        }

        if(winFactor == 3) {
            return 1;
        } else if(winFactor == -3) {
            return 2;
        }
    }

    return 0;
}

int TicTacToeBoard::spaceVerification(int row, int col) {
    row--;
    col--;

    if(row == -1) {
        return 1;
    } else if(gameBoard[row][col] != '*') {
        cout << "That space is already taken, try again.\n";
        return 1;
    } else {
        return 0;
    }
}

int TicTacToeBoard::inputValidation(int num) {
    if(num < 1 || num > 3) {
        cout << "\nNot a valid column.";
        return 1;
    } else {
        return 0;
    }
}

int main() {
    TicTacToeBoard board;

    board.printBoard();

    for(int turns = 0; turns < MAX_TURNS; turns++) {
        if(turns % 2 == 0) {
            board.xPlay();
        } else {
            board.oPlay();
        }
        board.printBoard();

        if(board.determineWinner() > 0) {
            if(board.determineWinner() == 1) {
                cout << "Player X Wins!" << endl;
            } else {
                cout << "Player O Wins!" << endl;
            }
            break;
        }
    }

    if(board.determineWinner() == 0) {
        cout << "It\'s a draw.\n" << endl;
    }
 
    return 0;
}


