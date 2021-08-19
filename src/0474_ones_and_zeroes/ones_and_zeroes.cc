// author: yqq
// date: 2021-08-18 15:10:46
// descriptions: https://leetcode-cn.com/problems/ones-and-zeroes/
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
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

 

示例 1：

输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：

输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 

提示：

1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100

*/


class Solution
{
public:
    // 01背包问题
    // dp[i][j][k]   从下标为[0-i]的物品里任意取，放进容量为j个0, k个1 背包中 子集最大的值
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size(); // 物品, string 中的 0 对应背包容量 m ， 1 对应背包容量 n
        // m , n 是背包容量
        vector< vector<vector<int>> > dp(size + 1, vector<vector<int>>( m + 1, vector<int>(n + 1, 0)));
        // 初始化
        //  dp[0][j][k] = 0
        //
        //
        // 递推公式：
        // 1.不放物品 i :  dp[i-1][j][k]
        // 2.放物品 i  :  dp[i-1][j - zeros][k - ones] + 1
        // dp[i][j][k] = max( dp[i-1][j][k] ,  dp[i - 1][j - zeros][k - ones] + 1 );
        //
        // 实现时，因 dp[0][j][k] 需要初始化为0，那么 dp[i][j][k]  对应的物品是 strs[i - 1], 所以， i要从1开始
        for(int i = 1; i < size + 1; i++ )
        {
            int zeros = 0;  // 字符串中 '0' 的个数
            int ones = 0;  //  字符串中 '1' 的个数
            for_each(strs[i - 1].begin(), strs[i - 1].end(), [&zeros, &ones](char ch){
                if('0' == ch) zeros++;
                else ones++;
            });

            for(int j = 0; j <= m; j++)
            {
                for(int k = 0; k <= n; k++)
                {
                    dp[i][j][k] = dp[i-1][j][k];
                    if( j - zeros >= 0 && k - ones >= 0) {
                        dp[i][j][k] = max( dp[i-1][j][k] ,  dp[i - 1][j - zeros][k - ones] + 1 );
                    }
                }
            }
        }
        return dp[size][m][n];
    }
};

void test(vector<string> strs, int m, int n, int expected)
{
    Solution sol;
    int result = sol.findMaxForm(strs, m, n);
    if(result != expected)
    {
        cout << "FAILED" << "  result " << result << "  expected " << expected << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({"10", "0", "1"}, 1, 1, 2);
    test({"10", "0001", "111001", "1", "0"}, 5, 3, 4);
    test({"111","1000","1000","1000"}, 9, 3, 3);
    test({"011111","001","001"}, 4, 5, 2);
    test({"11111","100","1101","1101","11000"}, 5, 7, 3);
    test({"0000111","0001","0000001111111","00011111","000011111","00000011","0111111","0000000001111111","0011","001111","00000001111","0011","0000111111111","0001111111","011111111"}, 4, 6, 2);
    return 0;
}

