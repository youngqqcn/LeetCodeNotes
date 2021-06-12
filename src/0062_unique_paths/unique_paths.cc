// author: yqq
// date: 2021-06-11 21:29:26
// descriptions: https://leetcode-cn.com/problems/unique-paths/
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
public:
    // 深度优先(leetcode 超时)
    int DFS(int row, int col, int m, int n)
    {
        if (row >= m || col >= n)
            return 0;
        if (row == m - 1 && col == n - 1)
            return 1;

        // 向下 + 向右
        return DFS(row + 1, col, m, n) + DFS(row, col + 1, m, n);
    }

    //  DP  动态规划
    int dpFunc(int m, int n)
    {
        // dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // dp数组初始化
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = 1;
        }

        // 遍历dp数组
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (0 == dp[i][j])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n)
    {
        // return DFS(0, 0, m, n);
        return dpFunc(m, n);
    }
};

void test(int m, int n, int expected)
{
    Solution sol;
    int result = sol.uniquePaths(m, n);
    cout << "result:" << result << endl;
    if (result != expected)
    {
        cout << "FAILED" << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test(3, 7, 28);
    test(3, 2, 3);
    test(2, 2, 2);
    test(7, 3, 28);
    test(3, 3, 6);

    // cout << "hello world" << endl;
    return 0;
}
