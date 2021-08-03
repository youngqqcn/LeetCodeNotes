// author: yqq
// date: 2021-08-02 11:58:21
// descriptions: https://leetcode-cn.com/problems/is-subsequence
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
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

 

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false
 

提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。

*/

class Solution
{
private:

    bool fStop;
    bool issubstr(string &s, int sstart, string &t, int tstart)
    {
        if(sstart >= s.length()) return true;
        for(int j = tstart; !fStop && j < t.size(); j++)
        {
            if(s[sstart] == t[j])  {
                if(issubstr(s, sstart + 1, t, j+1)) {
                    return true;
                }
            }
        }
        fStop = true; // 如果 s[sstart] 不在 t[tstart:] 后面也不必再搜索了
        return false;
    }

public:
    // 递归
    bool isSubsequence_v1(string s, string t)
    {
        fStop = false;
        return issubstr(s, 0, t, 0);
    }

    // 双指针
    bool isSubsequence_v2(string s, string t)
    {
        int slen = s.size(), tlen = t.size();
        int i = 0, j = 0;
        for( ; i < slen && j < tlen; j++)
        {
            if(s[i] == t[j]) {
                i++;
            }
        }
        return i == slen;
    }

    // 动态规划
    bool isSubsequence(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
};

void test(string s, string t, bool expected)
{
    Solution sol;
    if( expected != sol.isSubsequence(s, t))
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("abc", "ahbgdc", true);
    test("axc", "ahbgdc", false);
    test("rjufvjafbxnbgriwgokdgqdqewn", "mjmqqjrmzkvhxlyruonekhhofpzzslupzojfuoztvzmmqvmlhgqxehojfowtrinbatjujaxekbcydldglkbxsqbbnrkhfdnpfbuaktupfftiljwpgglkjqunvithzlzpgikixqeuimmtbiskemplcvljqgvlzvnqxgedxqnznddkiujwhdefziydtquoudzxstpjjitmiimbjfgfjikkjycwgnpdxpeppsturjwkgnifinccvqzwlbmgpdaodzptyrjjkbqmgdrftfbwgimsmjpknuqtijrsnwvtytqqvookinzmkkkrkgwafohflvuedssukjgipgmypakhlckvizmqvycvbxhlljzejcaijqnfgobuhuiahtmxfzoplmmjfxtggwwxliplntkfuxjcnzcqsaagahbbneugiocexcfpszzomumfqpaiydssmihdoewahoswhlnpctjmkyufsvjlrflfiktndubnymenlmpyrhjxfdcq", false);
    return 0;
}

