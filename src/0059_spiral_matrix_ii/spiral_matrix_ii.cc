// author: yqq
// date: 2021-06-07 18:05:10
// descriptions: https://leetcode-cn.com/problems/spiral-matrix-ii/
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
    enum Direction{
        RIGHT,
        DOWN,
        LEFT,
        UP,
    };
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int row = 0, col = 0; // 初始在位置(0，0)
        int count = 0;
        Direction lastDirection = Direction::RIGHT; // 初始方向， 右
        while(count <= n * n)
        {
            count++;
            v[row][col] = (count);

            // 1. 优先判断上一步的方向， 保持上一步的方向
            switch (lastDirection) {
            case Direction::RIGHT:
                if(col < n - 1 && 0 == v[row][col + 1]) {
                    col++;
                    continue; // for
                }
                break;
            case Direction::DOWN:
                if (row < n - 1 && 0 == v[row + 1][col]){
                    row++;
                    continue; // for
                } 
                break;
            case Direction::LEFT:
                if (0 < col && 0 == v[row][col - 1]) { 
                     col--;
                    continue; // for
                }
                break;
            case Direction::UP:
                if (0 < row && 0 == v[row - 1][col]) {
                    row--;
                    continue; // for
                }
                break;
            }

            // 2.如果不能按照上一步的方向继续， 则按照 “右”，“下”，“左”，“上”的优先级继续
            if (col < n - 1 && 0 == v[row][col + 1])
            {
                // right
                col++;
                lastDirection = Direction::RIGHT;
            }
            else if (row < n - 1 && 0 == v[row + 1][col])
            {
                // down
                row++;
                lastDirection = Direction::DOWN;
            }
            else if (0 < col && 0 == v[row][col - 1])
            {
                // left
                col--;
                lastDirection = Direction::LEFT;
            }
            else if (0 < row && 0 == v[row - 1][col])
            {
                // up
                row--;
                lastDirection = Direction::UP;
            }
            else
            {
                break;
            }
        }
        return v;
    }
};

void test(int n, vector<vector<int>> expected)
{
    Solution sol;
    vector<vector<int>> result = sol.generateMatrix(n);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     for (int j = 0; j < result[0].size(); j++)
    //     {
    //         cout << result[i][j] << " , ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    if(result != expected){
        cout << "FAILED" << endl;
    }else {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test(1, {{1}});
    test(3, {{1,2,3},{8,9,4},{7,6,5}});
    cout << "hello world" << endl;
    return 0;
}
