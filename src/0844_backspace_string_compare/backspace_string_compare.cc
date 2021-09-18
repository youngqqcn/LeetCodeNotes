// author: yqq
// date: 2021-09-18 16:24:38
// descriptions: https://leetcode-cn.com/problems/backspace-string-compare
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
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：

1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。
 

进阶：

你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？

*/

class Solution {
private:
    string parseInput(string s)
    {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {
            if('#' == s[i] ) {
                if(!stk.empty()) {
                    stk.pop();
                }
            }
            else {
                stk.push(s[i]);
            }
        }

        string result = string(stk.size(), '0');
        for(int i = stk.size() - 1; i >= 0  && !stk.empty(); i--)
        {
            result[i] = stk.top(); stk.pop();
        }
        return result;
    }
public:
    bool backspaceCompare(string s, string t)
    {
        string s1 = parseInput(s);
        string t1 = parseInput(t);
        return s1 == t1;
    }
};

void test(string s, string t, bool expected)
{
    Solution sol;
    bool result = sol.backspaceCompare(s, t);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("ab#c", "ad#c", true);
    test("ab##", "c#d#", true);
    test("a##c", "#a#c", true);
    test("a#c", "b", false);
    test("y#fo##f", "y#f#o##f", true);
    return 0;
}

