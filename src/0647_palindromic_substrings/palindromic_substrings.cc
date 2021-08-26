// author: yqq
// date: 2021-08-25 18:43:33
// descriptions: https://leetcode-cn.com/problems/palindromic-substrings
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
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 

提示：

输入的字符串长度不会超过 1000 。

*/


class Solution
{
private:
    bool isvalid(const string &s, int start, int end)
    {
        end--;
        while(start < end)
        {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    // 暴力求解
    int search(string s)
    {
        int result = s.size();
        for(int len = 2; len <= s.size(); len++)
        {
            for(int j = 0; j < s.size() && j + len <= s.size(); j++)
            {
                if(isvalid(s, j, j + len)) {
                    result++;
                }
            }
        }
        return result;
    }

    // 动态规划
    // 回文字符串:  去掉第1个和最后1个字符后仍然是回文字符串, 因此，可以缩小问题的规模，符合动态规划的条件
    // 此题和 回文子串 的不同之处在于，本题要求字符串是连续的，
    //
    //
    // dp[i][j] 表示区间范围[i,j] （注意是左闭右闭）的子串是否是回文子串，如果是dp[i][j]为true，否则为false。
    //
    // 当s[i]与s[j]不相等，那没啥好说的了，dp[i][j]一定是false。
    // 当s[i]与s[j]相等时，这就复杂一些了，有如下三种情况
    //
    // 情况一： 下标i 与 j相同，同一个字符例如a，当然是回文子串
    // 情况二： 下标i 与 j相差为1，例如aa，也是文子串
    // 情况三： 下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，
    //         我们看i到j区间是不是回文子串就看aba是不是回文就可以了，
    //         那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否为true。

    int search_v2(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;

        // 遍历顺序: 从下往上， 从左往右
        for(int i = s.size() ; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j])
                {
                    if(i == j) { // 情况1
                        dp[i][j] = true;
                        result++;
                    } else if(i + 1 == j) { // 情况2
                        dp[i][j] = true;
                        result++;
                    } else if(dp[i + 1][j - 1]){ // 情况3
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }


public:
    // 此题和最长回文子串类似
    int countSubstrings(string s)
    {
        // return search(s);
        return search_v2(s);
    }
};


void test(string s, int expected)
{
    Solution sol;
    int result = sol.countSubstrings(s);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("abc", 3);
    test("aaa", 6);
    test("world", 5);
    return 0;
}

