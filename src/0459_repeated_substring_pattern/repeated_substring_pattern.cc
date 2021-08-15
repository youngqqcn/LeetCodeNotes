// author: yqq
// date: 2021-08-15 10:28:45
// descriptions:
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

给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。

示例 1:

输入: "abab"

输出: True

解释: 可由子字符串 "ab" 重复两次构成。
示例 2:

输入: "aba"

输出: False
示例 3:

输入: "abcabcabcabc "

输出: True

解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
*/


class Solution {
public:
    bool repeatedSubstringPattern_v1(string s)
    {
        char *p = (char *)s.c_str();
        int len = 1;
        for(; len < s.length(); len++)
        {
            while(p[0] != (p+len)[0] && len < s.length()) {
                len++;
            }

            int j = len;
            for(; s.length() % len == 0 && j + len <= s.length(); j+= len)
            {
                if(0 != strncmp(p, p + j, len)) {
                    break;
                }

                if(j + len == s.length()) {
                    return true;
                }
            }
        }
        return false;
    }

    bool repeatedSubstringPattern_v2(string s) {
        return (s + s).find(s, 1) != s.size();
    }

    // 生成next树组
    void genNext(vector<int> &next, string needle)
    {
        // aabaaf
        // 1.初始化
        next.resize(needle.length());
        next[0] = 0; // 不减1
        int slow = 0, fast = 1;
        for (int fast = 1; fast < needle.size(); fast++)
        {
            // 2.处理前后缀不相同的情况
            while (slow > 0 && needle[slow] != needle[fast])
            {
                // 回退
                slow = next[slow - 1];
            }

            // 3.处理前后缀相同的情况
            if (needle[slow] == needle[fast])
            {
                slow++;
            }
            next[fast] = slow;
        }
    }

    /*
    最长相等前后缀的长度为：next[len - 1] + 1。
    数组长度为：len。
    如果len % (len - (next[len - 1] + 1)) == 0 ，则说明 (数组长度-最长相等前后缀的长度)
    正好可以被 数组的长度整除，说明有该字符串有重复的子字符串。



    **数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，
    如果这个周期可以被整除，就说明整个数组就是这个周期的循环。**
    */


    // 关于KMP的  前缀  后缀
    // 前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串；
    // 后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。
    bool repeatedSubstringPattern(string s)
    {
        vector<int> next(s.length(), 0);
        genNext(next, s);
        int len = s.length();

        // ?为什么?
        // 数组长度减去最长相同前后缀的长度相当于是第一个周期的长度，也就是一个周期的长度，
        // 如果这个周期可以被整除，就说明整个数组就是这个周期的循环
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }
};

void test(string s, bool expected)
{
    Solution sol;
    if( expected != sol.repeatedSubstringPattern(s) ) {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("abab", true);
    test("aba", false);
    test("abac", false);
    test("aabaaba", false);
    test("abcabcabcabc", true);

    return 0;
}

