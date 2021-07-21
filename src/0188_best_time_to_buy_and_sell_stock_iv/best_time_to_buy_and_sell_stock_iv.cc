// author: yqq
// date: 2021-07-08 15:39:44
// descriptions: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <iostream>
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
using namespace std;

/*
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
 

提示：

0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

*/





/*
    本题使用dp动态规划进行求解，对于动态规划问题，无非就是确定以下几个问题：
    1.dp函数的定义是什么？有几个状态？
    2.初始值如何确定？
    3.状态方程又是什么？
    对于以上三点，我觉得是处理好dp问题的重点，只有当我们明确以上几个问题之后，dp的思路就很清晰了，思路有了接下来就是码代码和处理细节/边界问题
    本题中存在三种「状态」：天数、是否持有股票的状态、交易次数
    而对于每种状态，我们又有不同的选择：
    1. 天数由prices确定
    2. 是否持有股票的状态我们可以用0/1表示，0代表不持有股票，1代表持有股票
    3. 交易次数由k确定

    这样一来，我们可以设定一个三维数组dp[i][j][k]，其存储的内容是在第i天，我们持有股票的状态为j，已经进行了k次交易时能够获取的最大利润
    这里需要说明的是，第i天和数组的索引一致，它的范围是0 ~ prices.length-1，所以我设置的起点是第0天
    比如说dp[5][0][2]：其中存储了 「在第5天时，我们不持有股票，已经进行了2次交易」 时获取的最大利润
    好了，到这里dp的定义和状态我们就确定下来了，那么初始值怎么确定呢？

    因为对于第0天来说，它所能够获取的最大利润只有两种，与交易次数毫无关系，所以我们有以下初始值：
    1.不持有股票时：dp[0][0][k]=0
    2.持有股票时：dp[0][1][k]=-prices[0]

    好了，到这里初始值也确定下来了，那么还剩下最后一个问题「状态方程」
    我们首先要知道一点，第i天的状态只和第i-1天有关，第i天持有/不持有股票 能够获取的最大利润取决于 第i-1天持有/不持有股票

    这里需要注意：我将买入股票时作为一次交易，也就是在买入股票的时候交易次数+1

    第i天不持有股票时：
        1.如果第i-1天也不持有股票，那就代表状态不变，第i天的状态=第i-1天的状态
        2.如果第i-1天持有股票，说明我们在第i天把股票卖了，既然卖股票赚钱了，利润就要多prices[i]

    dp[i][0][k] = max(dp[i-1][0][k] , dp[i-1][1][k]+prices[i])


    第i天持有股票时：
        1.如果第i-1天也持有股票，那就代表状态不变，即dp[i][1][k] = dp[i-1][1][k]
        2.如果第i-1天不持有股票，说明我们在第i天买入股票，既然买股票要花钱，利润就要少price[i]
        买入股票的同时，当天的交易次数要在前一天的基础上+1

    dp[i][1][k] = max(dp[i-1][1][k] , dp[i-1][0][k-1]-prices[i])


    至此，思路捋顺，开始码代码了！
    还需要注意的点：因为一次交易涉及一天买入一天卖出，一共两天，所以如果k值大于数组长度的一半，k就直接取数组长度的一半，因为多余的交易次数无法达到
    即：k=min(k , prices.length/2)

*/

class Solution
{
public:
    // 题解: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/javayi-ge-si-lu-da-bao-suo-you-gu-piao-t-pd1p/

    int maxProfit(int k, vector<int> &prices)
    {
        if(prices.size() < 2) return 0;
        int n = min(k, int(prices.size()/2)) + 1;
        vector<vector<vector<int>>>  dp( prices.size(),  vector<vector<int>>(n, vector<int>(2, 0)));
        for(int i = 0; i < n; i++)
        {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }

        for(int i = 1; i < prices.size(); i++)
        {
            for(int j = 1; j < n; j++)
            {
                // 不持有
                dp[i][j][0] = max( dp[i-1][j][0]/*昨天不持有*/ , dp[i-1][j][1] + prices[i] /*昨天持有, 今天卖了*/);

                // 持有
                // 因为只有买入, 才会对交易次数加1
                dp[i][j][1] = max( dp[i-1][j][1]/*昨天持有*/ , dp[i-1][j-1][0] - prices[i]  /*昨天不持有, 今天买了*/);
            }
        }
        return dp[prices.size() - 1][n - 1][0];
    }
};

void test(int k, vector<int> prices, int expected)
{
    Solution sol;
    auto result = sol.maxProfit(k, prices);
    if (result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test(2, {2, 4, 1}, 2);
    test(2, {3, 2, 6, 5, 0, 3}, 7);
    return 0;
}
