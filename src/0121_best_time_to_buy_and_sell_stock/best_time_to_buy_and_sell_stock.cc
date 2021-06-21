// author: yqq
// date: 2021-06-20 10:08:53
// descriptions: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
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
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。



示例 1：

输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。


示例 2：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
 

提示：

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4

*/


class Solution {
public:
    // 如果时间复杂度是 O(n^2) leetcode会超时
    // 这里使用贪心算法, 时间复杂度为O(n)
    int maxProfit_v0(vector<int>& prices)
    {
        if(prices.empty()) return 0;

        // 当前最大利益
        int curMaxProfit = 0;

        // 当前最小价格
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            // 贪心算法
            if(prices[i] < minPrice) {
                 minPrice = prices[i];
            }

            if(prices[i] > minPrice && prices[i] - minPrice > curMaxProfit) {
                curMaxProfit = prices[i] - minPrice;
            }
        }
        return curMaxProfit;
    }

    // 这种写法比较直观展现贪心算法
    int maxProfit_v2(vector<int>& prices) {
        int low = INT32_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);  // 取最左最小价格
            result = max(result, prices[i] - low); // 直接取最大区间利润
        }
        return result;
    }

    // TODO: 动态规划解法
    int maxProfit(vector<int>& prices)
    {
        if(prices.size() < 2) return 0;


        // dp[i][0] 表示第i天当前持有股票,"所获利"最多总现金(为了容易理解,不用"资产",而用现金)
        // dp[i][1] 表示第i天不持有股票,"所获利"最多总现金
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < dp.size(); i++)
        {
            // max(昨天就持有股票, 昨天没有持有股票今天以prices[i]价格买入了)
            dp[i][0] = max(dp[i - 1][0], -prices[i]);

            // max(昨天就不持有, 昨天持有今天以prices[i]价格卖掉了)
            dp[i][1] = max(dp[i - 1][1], dp[i-1][0] + prices[i]); // dp[i-1][0]表示昨天持有
        }
        return dp[dp.size()-1][1];
    }
};


void test(vector<int> prices, int expected)
{
    Solution sol;
    auto result = sol.maxProfit(prices);
    if(result != expected)
    {
        cout << "FAILED"  << " expected " << expected << " got " << result << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }

}

int main()
{
    test({7,1,5,3,6,4}, 5);
    test({7,6,4,3,1}, 0);
    cout << "hello world" << endl;
    return 0;
}

