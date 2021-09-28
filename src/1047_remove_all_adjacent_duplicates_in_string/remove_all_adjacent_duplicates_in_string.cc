// author: yqq
// date: 2021-09-28 09:43:52
// descriptions: https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
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
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

示例：

输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 

提示：

1 <= S.length <= 20000
S 仅由小写英文字母组成。

*/




class Solution
{
public:
    string removeDuplicates(string s)
    {
        string result;

        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }

        return result;
    }
};


void test(string s, string expected)
{
    Solution sol;
    auto result = sol.removeDuplicates(s);
    if(result != expected)
    {
        cout << "FAILED:" << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("abbaca", "ca");
    return 0;
}

