/*
 @Author Jason Zinn
 @Date April 1st, 2019
 *This is a simple Tic Tac Toe Game Written in C.
 */
#include <stdio.h>
#include <stdlib.h>
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
/* Here We Print The Board from Reference */
void printBoard()
{
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
    }
}
/* Create Syntactic Sugar for Array Locations */
char *one = &board[0][0];
char *two = &board[0][1];
char *three = &board[0][2];
char *four = &board[1][0];
char *five = &board[1][1];
char *six = &board[1][2];
char *seven = &board[2][0];
char *eight = &board[2][1];
char *nine = &board[2][2];
/* Return a pointer to mutate board location */
char* boardLocation(char input)
{
    /* Make Default imaginary */
    char waste = 'X';
    char* garbage = &waste;
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
            return garbage;
            break;
    }
}
/* Take Tic Tac Toe Pointer and apply */
void changeBoard(char input)
{
    char* temp = boardLocation(input);
    *temp = 'X';
}
/* Game Function */
void gameRequest()
{
    char locate;
    printf("Select a location => ");
    scanf("%c", &locate);
    changeBoard(locate);
    printBoard();
    printf("\n-------------------------------------------------\n");
    printf("Computer Turn");
    
}
/* Check for a Winner */
int checkWinner(char board[3][3])
{
    
    if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
        printf("GAME OVER");
        return 0;
    }
    else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        printf("GAME OVER");
        return 0;
    }
    else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
        printf("GAME OVER");
        return 0;
    }
    else if (board[2][2] == 'X' && board[2][1] == 'X' && board[2][0] == 'X') {
        printf("GAME OVER");
        return 0;
    }
    else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
        printf("GAME OVER");
        return 0;
    }
    else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') {
        printf("GAME OVER");
        return 0;
    }
    else {printf("! Have to crawl before you can walk !\n\n"); return 1;}
}
/*
** ~ Computer Turn ~
** This function takes a board and returns possible move locations
** Then it randomly selects one of these locations and mutates " | -> O "
 */
void computerTurn(char board[3][3])
{
    /* loop through board, count unaltered, make array with pointers to unaltered memory */
    int barCounter = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '|') {
                barCounter++;
            }
        }
    }
    /* Make a char ptr array of counter size */
    char *arr[barCounter];
    /* start from arr[0] of an arr which size is known and start placing board memlocs into the ptrs */
    int arrayIndexer = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '|') {
                arr[arrayIndexer] = & board[i][j];
                arrayIndexer++;
            }
        }
    }
    /* This component chooses a random location in the array */
    int randomLocationInArr = rand() % arrayIndexer;
    char *arrayOfPossibleMovesPtr = arr[randomLocationInArr];
    *arrayOfPossibleMovesPtr = 'O';
    printBoard();
    printf("\n-------------------------------------------------\n");
    printf("Your Turn");
}

/* Game Loop, run computer turn then gives player a chance then continue */
void gameLoop()
{
    while (checkWinner(board) != 0) {
        gameRequest();
        computerTurn(board);

        
    }
}

/* This is our main return function of our program */
int main()
{
    printf("~ Welcome to jason-zinn-engineering Tic Tac Toe ~\n");
    printf("-------------------------------------------------\n");
    instruct();
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("START!\n");
    gameLoop();
    return 0;
}
