// author: yqq
// date: 2021-08-23 18:56:22
// descriptions: https://leetcode-cn.com/problems/coin-change-2
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
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

示例 1：

输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


示例 2：

输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。

示例 3：

输入：amount = 10, coins = [10]
输出：1

提示：

1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins 中的所有值 互不相同
0 <= amount <= 5000

*/

class Solution
{
private:
    void show(const vector<int> &a)
    {
        for(int i = 0; i < a.size(); i++)
        {
            cout << a[i] << ",";
        }
        cout << endl;
        // cout << "===============" << endl;
    }
public:
    // 完全背包
    //
    // 动态规划
    //
    // dp[i] 表示 凑成i 的组合数
    //
    // dp[0] = 1  ,  即不选中任何硬币时为 0， 只有一种可能
    // dp[i] = dp[i - coins[j]]
    int change(int amount, vector<int>& coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        // cout << "===============" << endl;

        // 为什么先遍历硬币？
        // 因为这样可以不会计算重复的组合, 可以打印出dp数组看看
        for(int j = 0; j < coins.size(); j++)
        {
            for(int i = coins[j]; i <= amount; i++)
            {
                dp[i] += dp[i - coins[j]];
            }
            // show(dp);
        }

        // cout << "===============" << endl;
        return dp[dp.size() - 1];
    }
};

void test(int amount , vector<int> coins, int expected)
{
    Solution sol;
    auto result = sol.change(amount, coins);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test(5, {1, 2, 5}, 4);
    test(3, {2}, 0);
    test(10, {10}, 1);
    return 0;
}

