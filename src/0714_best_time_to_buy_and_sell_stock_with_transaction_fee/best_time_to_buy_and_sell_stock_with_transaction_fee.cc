// author: yqq
// date: 2021-09-15 16:33:09
// descriptions: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
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
给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。

 

示例 1：

输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

示例 2：

输入：prices = [1,3,7,5,10,3], fee = 3
输出：6


提示：

1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4

*/


class Solution
{
public:

    // 本题和0122类似，加入交易手续费
    // dp[i][0] 表示第i天当前持有股票,最多总现金(为了容易理解,不用"资产",而用现金)
    // dp[i][1] 表示第i天不持有股票,最多总现金
    int maxProfit(vector<int>& prices, int fee)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < dp.size(); i++)
        {
            // max(昨天就持有股票, 昨天没有持有股票今天以prices[i]价格买入了, )
            dp[i][0] = max({dp[i - 1][0], -prices[i] + dp[i-1][1]});

            // max(昨天就不持有, 昨天持有今天以prices[i]价格卖掉了 - 交易手续费)
            dp[i][1] = max(dp[i - 1][1], dp[i-1][0] + prices[i] - fee); // dp[i-1][0]表示昨天持有
        }
        return dp[dp.size()-1][1];
    }
};


void test(vector<int> prices, int fee, int expected)
{
    Solution sol;
    int result = sol.maxProfit(prices, fee);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, 3, 2, 8, 4, 9}, 2, 8);
    test({1,3,7,5,10,3}, 3, 6);

    return 0;
}

