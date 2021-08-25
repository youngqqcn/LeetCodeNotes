// author: yqq
// date: 2021-08-25 16:58:02
// descriptions: https://leetcode-cn.com/problems/delete-operation-for-two-strings
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
给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，
每步可以删除任意一个字符串中的一个字符。

 
示例：

输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
 

提示：

给定单词的长度不超过500。
给定单词中的字符只含有小写字母。

*/

class Solution
{
public:
    // 和 编辑距离 的题目很类似， 但又有不同
    // 不同之处在于： 编辑距离只能操作 word1 , 本题可以操作 word1 和 word2
    //
    // dp[i][j] 表以 word1[i - 1]结尾的子串 与 word2[j - 1] 结尾的子串最小距离
    //
    // 1.如果 word1[i - 1] = word2[j - 1]
    //    那么 dp[i][j] = dp[i - 1][j - 1]
    //
    // 2.如果 word1[i - 1] != word2[j - 1]
    //    在word1中删除字符word1[i - 1] :  dp[i][j] = dp[i - 1][j] + 1
    //    在word2中删除字符word2[j-1] :   dp[i][j] = dp[i][j - 1] + 1
    //    word1删除字符 word1[i - 1] 并且 word2删除字符 word2[j - 1] :  dp[i][j] = dp[i - 1][j - 1] + 2
    //
    //    综上：  dp[i][j] = min( dp[i - 1][j] + 1 , dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2)
    //
    // 初始化：
    //   dp[0][0] = 0   两个空串相等，不需要编辑
    //   dp[i][0] = i , dp[0][j]   一个空串与一个非空串的最小编辑距离就是非空串的长度
    //
    /*
     以 sea 和 eat为例, 推导dp数组:

              e   a   t
           0  1   2   3
        s  1  2   3   4
        e  2  1   4   5
        a  3  2   1   2

    */
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>( word2.size() + 1, 0));

        dp[0][0] = 0;
        for(int i = 0; i < dp.size(); i++) {
            dp[i][0] = i;
        }
        for(int i = 0; i < dp[0].size(); i++) {
            dp[0][i] = i;
        }

        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 1; j < dp[i].size(); j++)
            {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i-1][j-1] + 2});
                }
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};


void test(string word1, string word2, int expected)
{
    Solution sol;
    int result = sol.minDistance(word1, word2);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("a", "b", 2);
    test("sea", "eat", 2);
    return 0;
}

