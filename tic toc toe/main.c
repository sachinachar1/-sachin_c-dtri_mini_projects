#include <stdio.h>

char board[3][3];

void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}
int is_game_over() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;

    int tie = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                tie = 0;
                break;
            }
        }
        if (!tie) break;
    }
    if (tie) return -1;

    return 0;
}

void make_move(int row, int col, char symbol) {
    board[row][col] = symbol;
}

int main() {
    int row, col, player = 1, status;
    char symbol;

    initialize_board();

    do {
        player = (player % 2) ? 1 : 2;

        printf("Player %d, enter row (0-2) and column (0-2) to place your %c: ", player, (player == 1) ? 'X' : 'O');
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        }

        symbol = (player == 1) ? 'X' : 'O';

        make_move(row, col, symbol);
        display_board();
        status = is_game_over();

        player++;
    } while (status == 0);

    if (status == 1)
        printf("Player %d wins!\n", --player);
    else
        printf("It's a tie!\n");

    return 0;
}
