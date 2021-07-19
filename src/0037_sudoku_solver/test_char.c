#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sudoku_solver(char **board, int boardSize, int boardColSize)
{
    for(int i = 0; i < boardColSize; i++)
    {
        printf("%c", board[0][i]);
    }
    printf("\n");
}

int main()
{
    char *buf[] = {
        "2343243242"
    };
    char **pbuf1 = buf;
    char *(*pbuf2)[] = &buf;
    sudoku_solver(buf, sizeof(buf), strlen(buf[0]));
    return 0;

}
