// author: yqq
// date: 2021-07-04 14:53:46
// descriptions: https://leetcode-cn.com/problems/reverse-words-in-a-string/
#include <iostream>
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
using namespace std;

/*
给你一个字符串 s ，逐个翻转字符串中的所有 单词 。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。

说明：

输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
翻转后单词间应当仅用一个空格分隔。
翻转后的字符串中不应包含额外的空格。
 

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"
解释：输入字符串可以在前面或者后面包含多余的空格，但是翻转后的字符不能包括。

示例 3：
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，将翻转后单词间的空格减少到只含一个。

示例 4：
输入：s = "  Bob    Loves  Alice   "
输出："Alice Loves Bob"

示例 5：
输入：s = "Alice does not even like bob"
输出："bob like even not does Alice"

提示：
1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词

进阶：
请尝试使用 O(1) 额外空间复杂度的原地解法。
*/

class Solution
{
    vector<string> split(string &s)
    {
        vector<string> result;

        int i = 0;
        for (; i < s.length();)
        {
            if (s[i] == ' ')
            {
                i++;
                continue;
            }

            string str = "";
            while (i < s.length() && s[i] != ' ')
            {
                str.push_back(s[i]);
                i++;
            }
            if (!str.empty())
            {
                result.push_back(str);
            }
        }
        return std::move(result);
    }

public:
    string reverseWords(string s)
    {
        vector<string> words =  split(s);
        string result;
        for(auto it = words.begin(); it != words.end(); ++it)
        {
            if(!result.empty()) {
                result = (*it) + " " + result;
            }else {
                result = (*it) + result;
            }
        }
        return result;
    }
};

void test(string s, string expected)
{
    Solution sol;
    auto result = sol.reverseWords(s);
    if(result != expected) {
        cout << "FAILED" << endl;
    } else {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test("the sky is blue", "blue is sky the");
    test("  hello world  ", "world hello");
    test("a good   example", "example good a");
    test("  Bob    Loves  Alice   ", "Alice Loves Bob");
    test("Alice does not even like bob", "bob like even not does Alice");
    return 0;
}
