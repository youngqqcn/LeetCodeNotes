// author: yqq
// date: 2021-06-03 18:13:58
// descriptions:
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

// n皇后问题

class Solution
{
public:
    vector<vector<string>> result;
    vector<vector<char>> board;
    int nQueens = 0;

    bool check(int row, int col)
    {
        // 检查行
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] != '.')
                return false;
        }

        // 检查列
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i][col] != '.')
                return false;
        }

        // 检查对角线
        // 4个方向
        // NE  东北方向
        for (int i = row - 1, j = col + 1; 0 <= i && i < board.size() && 0 <= j && j < board.size(); i--, j++)
        {
            if (board[i][j] != '.')
            {
                return false;
            }
        }
        // SE 东南方向
        for (int i = row + 1, j = col + 1; 0 <= i && i < board.size() && 0 <= j && j < board.size(); i++, j++)
        {
            if (board[i][j] != '.')
            {
                return false;
            }
        }
        // SW 西南方向
        for (int i = row + 1, j = col - 1; 0 <= i && i < board.size() && 0 <= j && j < board.size(); i++, j--)
        {
            if (board[i][j] != '.')
            {
                return false;
            }
        }

        // NW 西北方向
        for (int i = row - 1, j = col - 1; 0 <= i && i < board.size() && 0 <= j && j < board.size(); i--, j--)
        {
            if (board[i][j] != '.')
            {
                return false;
            }
        }

        return true;
    }

    void solve(int startRow, int startCol)
    {
        // 递归终止
        if (board.size() == nQueens)
        {
            // 保存结果
            vector<string> solution;
            for (int row = 0; row < board.size(); row++)
            {
                string rowStr;
                for (int col = 0; col < board.size(); col++)
                {
                    rowStr.push_back(board[row][col]);
                }
                solution.push_back(rowStr);
            }
            result.push_back(solution);
            return;
        }

        for (int i = startRow; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (check(i, j))
                {
                    // 递归
                    board[i][j] = 'Q';
                    nQueens++;
                    solve(i, j);

                    // 回溯
                    board[i][j] = '.';
                    nQueens--;
                }
            }
        }
    }

    void initBoard(int n)
    {
        for (int i = 0; i < n; i++)
        {
            board.push_back(vector<char>(n, '.'));
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        initBoard(n);
        solve(0, 0);
        return result;
    }
};

void test(int n, set<vector<string>> expected)
{
    Solution sol;
    auto result = sol.solveNQueens(n);
    if (result.size() != expected.size())
    {
        cout << "FAILED: size isn't equal" << endl;
        return;
    }
    else
    {
        for (auto item : result)
        {
            if (expected.find(item) == expected.end())
            {
                cout << "FAILED" << endl;
                return;
            }
        }
        cout << "PASSED" << endl;
    }
}

int main()
{
    Solution sol;
    // sol.board = vector<vector<char>>({
    //     {'.', '.', '.', '.'},
    //     {'.', '.', 'Q', '.'},
    //     {'.', '.', '.', '.'},
    //     {'.', '.', '.', '.'},
    // });
    // if (!sol.check(0, 0))
    // {
    //     cout << "FAILED" << endl;
    // }
    // if (sol.check(1, 0))
    // {
    //     cout << "FAILED" << endl;
    // }
    // if (sol.check(0, 2))
    // {
    //     cout << "FAILED" << endl;
    // }
    // if (sol.check(0, 1))
    // {
    //     cout << "FAILED" << endl;
    // }
    // if (sol.check(2, 3))
    // {
    //     cout << "FAILED" << endl;
    // }
    // if (sol.check(2, 1))
    // {
    //     cout << "FAILED" << endl;
    // }


    //  sol.board = vector<vector<char>>({
    //     {'Q', '.', '.', '.'},
    //     {'.', '.', '.', 'Q'},
    //     {'.', '.', '.', '.'},
    //     {'.', '.', '.', '.'},
    // });
    // if (!sol.check(2, 1))
    // {
    //     cout << "FAILED" << endl;
    // } 


    test(4, {{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}});
    test(1, {{"Q"}});
    // cout << "hello world" << endl;
    return 0;
}
