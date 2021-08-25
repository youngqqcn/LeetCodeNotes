// author: yqq
// date: 2021-08-23 16:32:46
// descriptions: https://leetcode-cn.com/problems/longest-palindromic-subsequence
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
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

 

示例 1：

输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。
示例 2：

输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
 

提示：

1 <= s.length <= 1000
s 仅由小写英文字母组成

*/

class Solution
{
public:
    // 动态规划
    //
    // 官方题解： https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zui-chang-hui-wen-zi-xu-lie-by-leetcode-hcjqp/
    //
    // 问： 为什么能用动态规划？
    //
    // 答： 对于一个子序列而言，如果它是回文子序列，并且长度大于 2，那么将它首尾的两个字符去除之后，
    //      它仍然是个回文子序列。
    //      这样可以缩小问题的规模，子问题和总问题一样。
    //      因此可以用动态规划的方法计算给定字符串的最长回文子序列。
    //
    // dp[i][j] 表示 str[i : j] 子串的最长的回文子序列长度
    //
    //  1. 当 str[i] == str[j] 时，  dp[i][j] = dp[i + 1][j - 1] + 2
    //  2. 当 str[i] != str[j] 时，  dp[i][j] = max(dp[i + 1][j],  dp[i][j - 1]);
    //
    //
    // dp数组遍历顺序 ： 行：从下往上 , 列： 从左往右
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < dp.size(); i++)
        {
            dp[i][i] = 1;
        }

        for(int i = dp.size() - 1; i >= 0 ; i--)
        {
            for(int j = i+1; j < dp.size(); j++)
            {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j],  dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1 ];
    }
};


void test(string s,  int expected)
{
    Solution sol;
    auto result = sol.longestPalindromeSubseq(s);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("bbbab", 4);
    test("cbbd", 2);
    test("abcdcba", 7);
    return 0;
}

