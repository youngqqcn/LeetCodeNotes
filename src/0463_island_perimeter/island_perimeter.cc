// author: yqq
// date: 2021-08-18 14:19:45
// descriptions: https://leetcode-cn.com/problems/island-perimeter/
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

示例1：
输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
输出：16
解释：它的周长是上面图片中的 16 个黄色的边


示例 2：
输入：grid = [[1]]
输出：4

示例 3：
输入：grid = [[1,0]]
输出：4
 

提示：

row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] 为 0 或 1

*/


class Solution
{
private:
    int getEdgeLength(const vector<vector<int>>& grid, int row, int col)
    {
        int result = 4;

        // 上
        if(row - 1 >= 0 && 1 == grid[row - 1][col]) {
            result--;
        }

        // 下
        if(row + 1 < grid.size() && 1 == grid[row + 1][col]) {
            result--;
        }

        // 左
        if(col - 1 >= 0 && 1 == grid[row][col - 1]) {
            result--;
        }

        // 右
        if(col + 1 < grid[row].size() && 1 == grid[row][col + 1]) {
            result--;
        }
        return result;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int result = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[row].size(); col++)
            {
                if(1 == grid[row][col]) {
                    result += getEdgeLength(grid, row, col);
                }
            }
        }
        return result;
    }
};


void test(vector<vector<int>> grid, int expected)
{
    Solution sol;
    auto result =  sol.islandPerimeter(grid);
    if(result != expected) {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}}, 16);
    test({{1}}, 4);
    test({{1, 0}}, 4);
    return 0;
}

