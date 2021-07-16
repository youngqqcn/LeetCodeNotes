#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define false (0)
#define true (1)

bool isValid(int row, int col, char val, char (*board)[9])
{
    // 判断行里是否重复
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == val)
        {
            return false;
        }
    }

    // 判断列里是否重复
    for (int j = 0; j < 9; j++)
    {
        if (board[j][col] == val)
        {
            return false;
        }
    }

    // 判断9方格里是否重复
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool backtracking(char board[][9], int rowSize, int colSize)
{
    // char (*bd)[9] = (char (*)[9])board;
    // 遍历行
    for (int i = 0; i < rowSize; i++)
    {
        // 遍历列
        for (int j = 0; j < colSize; j++)
        {
            if (board[i][j] != '.')
                continue;

            // (i, j) 这个位置放k是否合适
            for (char k = '1'; k <= '9'; k++)
            {
                if (isValid(i, j, k, board))
                {
                    board[i][j] = k; // 放置k
                    if (backtracking(board, rowSize, colSize))
                        return true;   // 如果找到合适一组立刻返回
                    board[i][j] = '.'; // 回溯，撤销k
                }
            }
            return false; // 9个数都试完了，都不行，那么就返回false
        }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
}


void solveSudoku(char (*board)[9], int boardRowSize, int *boardColSize)
{
    backtracking(board, 9, 9);
}

int test()
{
    {
        char board[][9] = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

        char expected[][9] = {
            {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
            {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
            {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
            {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
            {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
            {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
            {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
            {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
            {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};

        int rowSize = 9, colSize = 9;
        solveSudoku(board, rowSize, &colSize);
        if (0 != memcmp(board, expected, rowSize * colSize))
        {
            printf("error 1\n");
            return 0;
        }
    }
    return 0;
}

int main()
{
    return test();
}