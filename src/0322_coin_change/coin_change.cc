// author: yqq
// date: 2021-07-28 17:12:11
// descriptions: https://leetcode-cn.com/problems/coin-change
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

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2
 

提示：

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 104


*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end());
        if(amount <= 0) return 0;

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size() && coins[j] <= i; j++)
            {
                if(dp[ i - coins[j] ]  != INT_MAX) {
                    dp[i] = min(dp[ i - coins[j] ]  + 1 , dp[i]);
                }
            }
        }
        return (dp[amount] != INT_MAX) ? (dp[amount]): (-1);
    }
};



void test(vector<int> coins, int amount, int expected)
{
    Solution sol;
    auto result = sol.coinChange(coins, amount);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}



int main()
{
    test({1, 2, 5}, 11, 3);
    test({2}, 3, -1);
    test({1}, 0, 0);
    test({1}, 1, 1);
    test({1}, 2, 2);
    return 0;
}

