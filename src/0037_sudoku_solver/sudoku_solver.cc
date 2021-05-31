// author: yqq
// date: 2021-05-31 21:02:49
// descriptions: https://leetcode-cn.com/problems/sudoku-solver/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

class Solution
{
private:
    bool backtracking(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        { // 遍历行
            for (int j = 0; j < board[0].size(); j++)
            { // 遍历列
                if (board[i][j] != '.')
                    continue;
                for (char k = '1'; k <= '9'; k++)
                { // (i, j) 这个位置放k是否合适
                    if (isValid(i, j, k, board))
                    {
                        board[i][j] = k; // 放置k
                        if (backtracking(board))
                            return true;   // 如果找到合适一组立刻返回
                        board[i][j] = '.'; // 回溯，撤销k
                    }
                }
                return false; // 9个数都试完了，都不行，那么就返回false
            }
        }
        return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
    }
    bool isValid(int row, int col, char val, vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        { // 判断行里是否重复
            if (board[row][i] == val)
            {
                return false;
            }
        }
        for (int j = 0; j < 9; j++)
        { // 判断列里是否重复
            if (board[j][col] == val)
            {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++)
        { // 判断9方格里是否重复
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

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        backtracking(board);
    }
};

void test(vector<vector<char>> &board, vector<vector<char>> &expected)
{
    Solution sol;
    sol.solveSudoku(board);
    if(board != expected){
        cout << "FAILED" << endl;
    }else {
        cout << "PASSED" << endl;
    }
}

int main()
{
    auto board = vector<vector<char>>(
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}});

    auto expected = vector<vector<char>>(
        {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
         {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
         {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
         {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
         {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
         {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
         {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
         {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
         {'3', '4', '5', '2', '8', '6', '1', '7', '9'}});

    test(board, expected);

    cout << "hello world" << endl;
    return 0;
}
