// author: yqq
// date: 2021-07-27 11:39:02
// descriptions: https://leetcode-cn.com/problems/valid-anagram
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
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

 

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
 

提示:

1 <= s.length, t.length <= 5 * 10^4
s 和 t 仅包含小写字母
 

进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

*/



// unicode 字符串可以使用   std::wstring  wchar_t

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> sdict;
        unordered_map<char, int> tdict;
        for(int i = 0; i < s.length(); i++)
        {
            sdict[ s[i] ] += 1;
            tdict[ t[i] ] += 1;
        }
        return sdict == tdict;
    }
};

void test(string s, string t, bool expected)
{
    Solution sol;
    auto result = sol.isAnagram(s, t);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("anagram", "nagaram", true);
    test("rat", "car", false);
    return 0;
}

