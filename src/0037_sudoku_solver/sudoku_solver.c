#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int bool;
#define false (0)
#define true (1)

bool isValid(int row, int col, char val, char **board)
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

bool backtracking(char **board, int rowSize, int colSize)
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

// void solveSudoku(char (*board)[9], int boardRowSize, int *boardColSize)
void solveSudoku(char **board, int boardRowSize, int *boardColSize)
{
    backtracking(board, 9, 9);
}


// void readFile(char *filename, char **board, int rowSize, int colSize)
// {
//     FILE *fp = fopen(filename, "r");
//     if(NULL == fp) {
//         printf("error fopen\n");
//         return;
//     }

//     if(NULL == board) {
//         board = (char **)calloc(rowSize * colSize, 1);
//     }

//     for(int i = 0; i < rowSize; i++)
//     {
//         int ret = fgets(board[i], 9, fp);
//         if(ret <= 0) break;
//     }
//     fclose(fp);
// }

int test()
{
    {
        char *constBoard[] = {
            "53..7....",
            "6..195...",
            ".98....6.",
            "8...6...3",
            "4..8.3..1",
            "7...2...6",
            ".6....28.",
            "...419..5",
            "....8..79"};

        char *expected[] = {
            "534678912",
            "672195348",
            "198342567",
            "859761423",
            "426853791",
            "713924856",
            "961537284",
            "287419635",
            "345286179"};

        int rowSize = 9, colSize = 9;

        // 将字符串从 .text区(不可修改), 拷贝到内存(可修改)
        char **board = (char **)calloc(rowSize, sizeof(char *));
        for(int i = 0; i < rowSize; i++)
        {
            board[i] = (char *)calloc(strlen(constBoard[i]), 1);
            memcpy(board[i], constBoard[i], strlen(constBoard[i]));
        }

        solveSudoku(board, rowSize, &colSize);
        for(int i = 0; i < rowSize; i++)
        {
            if (0 != memcmp(board[i], expected[i], strlen(expected[i])) )
            {
                printf("error 1\n");
                return 0;
            }
        }

        //  释放内存
        for(int i = 0; i < rowSize; i++)
        {
            free(board[i]);
        }
        free(board);
    }

    {
        char *constBoard[] = {
            "..9748...",
            "7........",
            ".2.1.9...",
            "..7...24.",
            ".64.1.59.",
            ".98...3..",
            "...8.3.2.",
            "........6",
            "...2759.."};

        char *expected[] = {
            "519748632",
            "783652419",
            "426139875",
            "357986241",
            "264317598",
            "198524367",
            "975863124",
            "832491756",
            "641275983"};

         int rowSize = 9, colSize = 9;

        // 将字符串从 文字常量区(不可修改), 拷贝到内存(可修改)
        char **board = (char **)calloc(rowSize, sizeof(char *));
        for(int i = 0; i < rowSize; i++)
        {
            board[i] = (char *)calloc(strlen(constBoard[i]), 1);
            memcpy(board[i], constBoard[i], strlen(constBoard[i]));
        }

        solveSudoku(board, rowSize, &colSize);
        for(int i = 0; i < rowSize; i++)
        {
            if (0 != memcmp(board[i], expected[i], strlen(expected[i])) )
            {
                printf("error 1\n");
                return 0;
            }
        }

        //  释放内存
        for(int i = 0; i < rowSize; i++)
        {
            free(board[i]);
        }
        free(board);
    }
    return 0;
}

int main()
{
    return test();
}