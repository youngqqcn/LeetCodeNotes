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

    // TODO: 动态规划
    int search_v2(string s)
    {
        return 0;
    }


public:
    // 此题和最长回文子串类似
    int countSubstrings(string s)
    {
        return search(s);
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

