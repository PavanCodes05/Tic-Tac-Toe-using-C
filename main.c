#include <stdio.h>
#include <stdbool.h>

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
    // Initial State
    displayGameboard(board);

    // Player turn

    // flag to end the game
    char winner = ' ';
    
    while (true) {
        printf("\n\n");
        printf("%c 's Turn\n", currentPlayer);
        getPlayerInput();
        displayGameboard(board);
        winner = determineWinner(board);

        if (winner == 'X' || winner == 'O') {
            break;
        }
        // Check for free grids
    };
    printf("\n\n");
    printf("%c Wins\n", winner);
    printf("\n\n");

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
    } 
    return;
};

char determineWinner(char board[3][3]) {
    // Horizontal Checks
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ') {
        return board[0][0];
    } else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ') {
        return board[1][1];
    } else if(board[2][0] == board[2][1] && board[1][1] == board[2][2] && board[2][0] != ' ') {
        return board[2][0];
    };  

    // Vertical Checks
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ') {
        return board[0][0];
    } else if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ') {
        return board[0][1];
    } else if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ') {
        return board[0][2];
    };

    // Diagonal Checks 
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    } else if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    };

    return ' ';
};