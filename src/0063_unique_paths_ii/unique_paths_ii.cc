// author: yqq
// date: 2021-06-12 16:06:53
// descriptions: https://leetcode-cn.com/problems/unique-paths-ii/submissions/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

class Solution {
public:
    // 动态规划
    int dpFunc(vector<vector<int>> &obstacleGrid)
    {
        // 初始化
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if(1 == obstacleGrid[0][0] ){
            return 0;
        }
        dp[0][0] = 1;
        for(int i = 1; i < m; i++){
            if(0 != obstacleGrid[i][0]){
                dp[i][0] = 0;
                // 将本格和后面的都设置为0,  因为dp初始化全部为0,所以可以直接break
                break;
            }else{
                dp[i][0] = 1;
            }
        }

        for(int i = 1; i < n; i++){
            if(0 != obstacleGrid[0][i]) {
                dp[0][i] = 0;
                // 将本格和后面的都设置为0,  因为dp初始化全部为0,所以可以直接break
                break;
            }else{
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++) {
                if(1 == obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        return dpFunc(obstacleGrid);
    }
};


void test(vector<vector<int>> obstacleGrid, int expected)
{
    Solution sol;
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    if(result != expected)
    {
        cout << "FAILED" << " result is " << result << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({{0,0,0},{0,1,0},{0,0,0}}, 2);
    test( {{0,1},{0,0}}, 1);
    cout << "hello world" << endl;
    return 0;
}

