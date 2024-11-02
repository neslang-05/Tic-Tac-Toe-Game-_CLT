#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char symbol);
bool checkWin(char board[3][3], char symbol);
bool isBoardFull(char board[3][3]);
bool isValidMove(char board[3][3], int row, int col);

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;
    int row, col;
    
    initializeBoard(board);
    
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("Enter moves using row (1-3) and column (1-3)\n\n");
    
    while (!gameWon && !isBoardFull(board)) {
        displayBoard(board);
        printf("\nPlayer %c's turn\n", currentPlayer);
        
        do {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            
            // Adjust for 0-based indexing
            row--;
            col--;
            
            if (!isValidMove(board, row, col)) {
                printf("Invalid move! Try again.\n");
            }
        } while (!isValidMove(board, row, col));
        
        makeMove(board, row, col, currentPlayer);
        
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("\nPlayer %c wins!\n", currentPlayer);
            gameWon = true;
        } else if (isBoardFull(board)) {
            displayBoard(board);
            printf("\nGame is a draw!\n");
        }
        
        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

bool makeMove(char board[3][3], int row, int col, char symbol) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = symbol;
        return true;
    }
    return false;
}

bool checkWin(char board[3][3], char symbol) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return true;
        }
    }
    
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return true;
    }
    
    return false;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}