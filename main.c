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
/* Define Repeat Instructions */
void instruct()
{
    printf("[1][2][3]\n[4][5][6]\n[7][8][9]\nThese are the keys that you will use to pick your position\n");
}
/* Return a pointer to mutate board location */
char* boardLocation(char input)
{
    switch (input) {
        case '1':
            return &board[0][0];
            break;
        case '2':
            return &board[0][1];
            break;
        case '3':
            return &board[0][2];
            break;
        case '4':
            return &board[1][0];
            break;
        case '5':
            return &board[1][1];
            break;
        case '6':
            return &board[1][2];
            break;
        case '7':
            return &board[2][0];
            break;
        case '8':
            return &board[2][1];
            break;
        case '9':
            return &board[2][2];
            break;
        default:
            return &board[1][1];
            break;
    }
}

/*  */

int main()
{
    printf("~ Welcome to jason-zinn-engineering Tic Tac Toe ~\n");
    printf("-------------------------------------------------\n");
    instruct();
    return 0;
}
