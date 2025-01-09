#include <stdio.h>

void displayGameboard(char board[3][3]);
char determineWinner(char board[3][3]);

int main() {
    char board[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    displayGameboard(board);
    return 0;
};

void displayGameboard(char board[3][3]) {
    int i, j;
    for(i = 0;i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("|");
            printf(" %d ", board[i][j]);
            printf("|");
        }
        printf("\n");
    }   

};

char determineWinner(char board[3][3]) {

};