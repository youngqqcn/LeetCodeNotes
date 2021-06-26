// author: yqq
// date: 2021-06-26 15:55:10
// descriptions: https://leetcode-cn.com/problems/palindrome-partitioning
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
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。

 

示例 1：

输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]
示例 2：

输入：s = "a"
输出：[["a"]]
 

提示：

1 <= s.length <= 16
s 仅由小写英文字母组成


*/

// 思路:
// 方法1: 求出所有排列可能, 取出所有是回文串的可能
// 方法2: 求出正序字符串所有排列可能, 再求出反序字符串所有排列可能, 取交集就是所有的回文串
// 方法3: 回文串s = s1+s2+s3 , s1 == s3' ,即 s1必须等于反序的s3,  s2长度为大于等于0

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if(s.length() == 1) return true;

        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    int length = 0;
    vector<string> oneResult;
    vector<vector<string>> result;

    void split(string s, int startIndex)
    {
        // 递归终止
        if (s.length() == length)
        {
            result.push_back(oneResult);
            return;
        }

        for (int len = 1; len <= s.length() && startIndex + len <= s.length(); len++)
        {
            string substr = s.substr(startIndex, len);
            if (isPalindrome(substr))
            {
                length += substr.length();
                oneResult.push_back(substr);

                split(s, startIndex + len);

                // 回溯
                oneResult.pop_back();
                length -= substr.length();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        result.clear();
        oneResult.clear();
        split(s, 0);
        return result;
    }
};

void test(string s, set<vector<string>> expected)
{
    Solution sol;
    auto result = sol.partition(s);
    if (result.size() != expected.size())
    {
        cout << "FAILED" << endl;
        return;
    }

    for (auto item : result)
    {
        auto it = expected.find(item);
        if (it == expected.end())
        {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("aab", {{"a", "a", "b"}, {"aa", "b"}});
    test("cdd", {{"c", "d", "d"}, {"c", "dd"}});
    test("a", {{"a"}});
    // cout << "hello world" << endl;
    return 0;
}
