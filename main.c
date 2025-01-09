#include <stdio.h>

void displayGameboard(char board[3][3]);
char determineWinner(char board[3][3]);
void getPlayerInput();

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

char currentPlayer = 'X';

int main() {
    displayGameboard(board);
    getPlayerInput();
    return 0;
};

void displayGameboard(char board[3][3]) {
    int i, j;
    for(i = 0;i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("|");
            printf(" %c ", board[i][j]);
            printf("|");
        }
        printf("\n");
    }   

};

void getPlayerInput() {
    // char getPlayerTurn()
    int row, col;
    printf("Enter the row: ");
    scanf("%d", &row);
    
    printf("Enter the column: ");
    scanf("%d", &col);

    if (row > 3 || col > 3) {
        printf("Invalid\n");
        return;
    };

    if (board[row - 1][col - 1] == ' '){
        board[row - 1][col - 1] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
        displayGameboard(board);
    };
    return 0;
};

// char determineWinner(char board[3][3]) {

// };