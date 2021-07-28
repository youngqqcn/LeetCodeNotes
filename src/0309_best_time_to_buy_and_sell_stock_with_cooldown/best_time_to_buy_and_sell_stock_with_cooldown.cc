// author: yqq
// date: 2021-07-28 15:31:18
// descriptions: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
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
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

*/

class Solution
{
public:
    // https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/

    // dp[i] 表示第 i 天结束之后的「累计最大收益」
    //
    // 3种状态
    // 状态1: 我们目前持有一支股票，对应的「累计最大收益」记为 dp[i][0]；
    // 状态2: 我们目前不持有任何股票，并且处于冷冻期中，对应的「累计最大收益」记为 dp[i][1]；
    // 状态3: 我们目前不持有任何股票，并且不处于冷冻期中，对应的「累计最大收益」记为 dp[i][2]。
    //
    // ! 特别注意: 这里的「处于冷冻期」指的是在第 i 天结束之后的状态。也就是说：如果第 i 天结束之后处于冷冻期，那么第 i+1 天无法买入股票。
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
            return 0;

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < n; i++)
        {
            // 状态1:
            //    a) 昨天就持有, 即 , dp[i - 1][0]
            //    b) 今天买入的, 那么第i-1天不持有股票, 且第i-1结束后不处于冷冻期,即对应昨天的 状态3, 即 dp[i - 1][2] ,
            //         加上今天买入股票的负收益-prices[i]
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);

            // 状态2:
            //   a) 今天卖了, 那么昨天持有股票, 即 dp[i][0] , 加上卖掉的正收益, dp[i][0] + prices[i]
            dp[i][1] = dp[i - 1][0] + prices[i];

            // 状态3:
            //   a) 昨天也不持有且不处于冷冻期, 今天没操作, 沿用昨天的状态3, 即dp[i-1][2]
            //   b) 前天卖了股票, 昨天是冷冻期, 不能买入, 昨天不持有, 到今天冷冻期已过,  但今天没操作, 所以沿用昨天的状态2, 即 dp[i-1][1]
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }

        return max(dp[n-1][1], dp[n-1][2]);
    }
};

void test(vector<int> prices, int expected)
{
    Solution sol;
    auto result = sol.maxProfit(prices);
    if (result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, 2, 3, 0, 2}, 3);
    return 0;
}
