// author: yqq
// date: 2021-06-20 11:03:09
// descriptions: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
using namespace std;

/*
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入: prices = [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
示例 2:

输入: prices = [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: prices = [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 3 * 10^4
0 <= prices[i] <= 10^4

*/



// 思路:
//   贪心算法:
//      如果明天的股价大于今天, 且当前没有持有股票, 则今天买入
//      如果明天的股价小于今天, 且当前持有股票, 则今天卖出

class Solution
{
public:

    // 贪心算法
    int maxProfit_v1(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;

        int sumProfit = 0;
        int buyPrice = 0;
        bool hold = false; // 是否持有股票

        // 处理边界问题, 如果遍历到最后一个,估价仍然是上涨,也得卖掉. 所以,在末尾添加一个负数, 来模拟股价下跌
        prices.push_back(INT32_MIN);

        int lastPrice = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            // 因为上面在末尾添加了一个 -1, 所以不会越界
            int tommorowPrice = prices[i + 1];

            // 如果明天股价下跌, 如果有持有, 则卖出
            if (hold && prices[i] > tommorowPrice)
            {
                // 卖出
                hold = false;
                sumProfit += prices[i] - buyPrice;
                continue;
            }

            // 如果明天股价上涨, 如果当前没有持有, 则买入
            if (!hold && prices[i] < tommorowPrice)
            {
                // 买入
                hold = true;
                buyPrice = prices[i];
                continue;
            }
        }
        return sumProfit;
    }

    int maxProfit_v2(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 贪心: 只累加正利润
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }

    // 动态规划
    int maxProfit(vector<int> &prices)
    {
        

    }
};

void test(vector<int> prices, int expected)
{
    Solution sol;
    // prices.resize(prices.size());
    auto result = sol.maxProfit(prices);
    if (result != expected)
    {
        cout << "FAILED "  << " expected " << expected << " got " << result << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({7, 1, 5, 3, 6, 4}, 7);
    test({1, 2, 3, 4, 5}, 4);
    test({7, 6, 4, 3, 1}, 0);
    test({1}, 0);
    test({1, 2}, 1);
    cout << "hello world" << endl;
    return 0;
}
