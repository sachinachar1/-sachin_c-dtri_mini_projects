#include <stdio.h>

// Function to display the Tic Tac Toe board
void displayBoard(char board[3][3]) {
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
char checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0]; // Return the winning player's symbol
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i]; // Return the winning player's symbol
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0]; // Return the winning player's symbol
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2]; // Return the winning player's symbol
    }
    return ' '; // Return space if no winner yet
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    while (winner == ' ') {
        // Display the board
        displayBoard(board);

        // Player's move
        printf("Player %c's turn.\nEnter row and column (0-2):\n ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the cell is empty
        if (board[row][col] == ' ') {
            // Place the player's symbol on the board
            board[row][col] = currentPlayer;

            // Check if the current player has won
            winner = checkWin(board);

            // Switch player
            if (currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        } else {
            printf("That cell is already occupied. Try again.\n");
        }
    }

    // Display the final board
    displayBoard(board);

    // Display the winner
    if (winner == 'X' || winner == 'O')
        printf("Player %c wins!\n", winner);
    else
        printf("It's a draw!\n");

    return 0;
}

