// author: yqq
// date: 2021-07-30 10:11:01
// descriptions: https://leetcode-cn.com/problems/reverse-string
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
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须 原地 修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

 

示例 1：

输入：["h","e","l","l","o"]
输出：["o","l","l","e","h"]
示例 2：

输入：["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]

*/

class Solution
{
public:
    void reverseString(vector<char>& s)
    {
        for(int head = 0, tail = s.size() - 1; head < tail; head++, tail--)
        {
            swap(s[head], s[tail]);
        }
    }
};

void test(vector<char> s, vector<char> expected)
{
    Solution sol;
    sol.reverseString(s);
    if(expected != s)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({'h','e','l','l','o'}, {'o','l','l','e','h'});
    test({'H','a','n','n','a','h'}, {'h','a','n','n','a','H'});
    return 0;
}

