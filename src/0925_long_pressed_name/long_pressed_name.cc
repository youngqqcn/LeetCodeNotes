// author: yqq
// date: 2021-09-19 11:02:35
// descriptions: https://leetcode-cn.com/problems/long-pressed-name
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
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。

示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。

示例 3：

输入：name = "leelee", typed = "lleeelee"
输出：true

示例 4：

输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。
 

提示：

name.length <= 1000
typed.length <= 1000
name 和 typed 的字符都是小写字母。


*/

class Solution {
public:
    bool isLongPressedName(string name, string typed)
    {
        if(name[0] != typed[0] || name.length() > typed.length()) {
            return false;
        }

        int idx = 0; // name的索引
        char last; // 上个匹配字符
        for(int i = 0; i < typed.length(); i++)
        {
            if(idx < name.length() && name[idx] == typed[i]) {
                last = name[idx];
                idx++;
            }else if (last == typed[i]) {
                continue;
            } else {
                return false;
            }
        }
        return idx == name.length() ;
    }
};


void test(string name, string typed, bool expected)
{
    Solution sol;
    auto result = sol.isLongPressedName(name, typed);
    if(expected != result)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("alex", "aaleex", true);
    test("saeed", "ssaaedd", false);
    test("leelee", "lleeelee", true);
    test("laiden", "laiden", true);
    test("alexd", "ale", false);
    test("pyplrz", "ppyypllr", false);
    test("vtkgn", "vttkgnn", true);
    return 0;
}

