// author: yqq
// date: 2021-09-17 11:31:26
// descriptions: https://leetcode-cn.com/problems/min-cost-climbing-stairs
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
数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。

每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。

请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。


示例 1：

输入：cost = [10, 15, 20]
输出：15
解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。

示例 2：

输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出：6
解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
 

提示：

cost 的长度范围是 [2, 1000]。
cost[i] 将会是一个整型数据，范围为 [0, 999] 。
*/

class Solution {
public:
    // dp[i][0]  往后跳两步
    // dp[i][1]  往后跳一步
    //
    //
    // dp[i][0] = cost[i] + min(dp[i + 1][0], dp[i + 1][1]);
    // dp[i][1] = cost[i] + min(dp[i + 2][0], dp[i + 2][1]);
    //
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // 初始化
        dp[n - 1][0] = cost[n - 1];
        dp[n - 1][1] = cost[n - 1];
        dp[n - 2][0] = cost[n - 2] + cost[n - 1];
        dp[n - 2][1] = cost[n - 2];

        for(int i = n - 3; i >= 0; i--)
        {
            // 递推公式
            dp[i][0] = cost[i] + min(dp[i + 1][0], dp[i + 1][1]);
            dp[i][1] = cost[i] + min(dp[i + 2][0], dp[i + 2][1]);
        }

        int result = min({dp[0][0], dp[0][1], dp[1][0], dp[1][1]});
        return result;
    }
};

void test(vector<int> cost, int expected)
{
    Solution sol;
    if( expected != sol.minCostClimbingStairs(cost) )
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({10, 15, 20}, 15);
    test({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6);
    return 0;
}

