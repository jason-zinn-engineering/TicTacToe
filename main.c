/*
 @Author Jason Zinn
 @Date April 1st, 2019
 */
#include <stdio.h>
/* Define Board */
char board[3][3] = {
    {'|','|','|'},
    {'|','|','|'},
    {'|','|','|'}
};
/* Define Board Print Function */
void boardPrinter(char board[3][3])
{
    printf(board[0]);
    printf("\n");
    printf(board[1]);
    printf("\n");
    printf(board[2]);
    printf("\n");
}

int main()
{
    printf("~ Welcome to jason-zinn-engineering Tic Tac Toe ~\n");
    printf("-------------------------------------------------\n");
    printf("[1][2][3]\n[4][5][6]\n[7][8][9]\n");
    boardPrinter(board);
    return 0;
}
