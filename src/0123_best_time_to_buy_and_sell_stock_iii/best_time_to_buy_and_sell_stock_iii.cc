// author: yqq
// date: 2021-06-21 10:52:06
// descriptions: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
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

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

示例 1:

输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2：

输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。  
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。  
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3：

输入：prices = [7,6,4,3,1]
输出：0
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。
示例 4：

输入：prices = [1]
输出：0
 

提示：

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5

*/

/*

 思路:
    1.最多买卖2次, 可以不买卖, 也可以买卖1次或2次
    2.比较难的点是, 如何构造状态转移数组,
           关于如何构造状态转移: 这个官方题解写的非常清晰, 非常值得学习
           https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iii-by-wrnt/

由于我们最多可以完成两笔交易，因此在任意一天结束之后，我们会处于以下五个状态中的一种：
    1.未进行过任何操作；
    2.只进行过一次买操作；
    3.进行了一次买操作和一次卖操作，即完成了一笔交易；
    4.在完成了一笔交易的前提下，进行了第二次买操作；
    5.完成了全部两笔交易。

*/



class Solution
{
public:
    // 暴力
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> profits;
        for(int i = 0; i < prices.size(); i++) {
            vector<int> profit;
            for(int j = i+1; j < prices.size(); j++) {
                profit.push_back( prices[j] - prices[i]);
            }
        }
    }
};

void test(vector<int> prices, int expected)
{
    Solution sol;
    // prices.resize(prices.size());
    auto result = sol.maxProfit(prices);
    if (result != expected)
    {
        cout << "FAILED "
             << " expected " << expected << " got " << result << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({3, 3, 5, 0, 0, 3, 1, 4}, 6);
    test({1, 2, 3, 4, 5}, 4);
    test({7, 6, 4, 3, 1}, 0);
    test({1}, 0);
    cout << "hello world" << endl;
    return 0;
}
