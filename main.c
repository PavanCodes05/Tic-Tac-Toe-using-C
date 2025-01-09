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

char determineWinner(char board[3][3]) {
    // Horizontal Checks
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) {
        return board[0][0];
    } elif (board[1][0] == board[1][1] && board[1][1] == board[1][2]) {
        return board[1][1];
    } elif(board[2][0] == board[2][1] && board[1][1] == board[2][2]) {
        return board[2][0];
    };

    // Vertical Checks
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
        return board[0][0];
    } elif(board[0][1] == board[1][1] && board[1][1] == board[2][1]) {
        return board[0][1];
    } elif(board[0][2] == board[1][2] && board[1][2] == board[2][2]) {
        return board[0][2]
    }

    // Diagonal Checks
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    } elif(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
};