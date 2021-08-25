// author: yqq
// date: 2021-08-25 15:41:33
// descriptions: https://leetcode-cn.com/problems/reverse-string-ii
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
给定一个字符串 s 和一个整数 k，从字符串开头算起，每 2k 个字符反转前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 

示例 1：

输入：s = "abcdefg", k = 2
输出："bacdfeg"
示例 2：

输入：s = "abcd", k = 2
输出："bacd"
 

提示：

1 <= s.length <= 10^4
s 仅由小写英文组成
1 <= k <= 10^4

*/

class Solution
{
private:

public:
    void reverse(string &s, int start, int end)
    {
        end--;
        while(start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseStr(string s, int k)
    {
        int start = 0;
        int end = 0;
        for( ; ; )
        {
            start = end;
            end += 2 * k;
            if(end > s.length())
            {
                int left = s.length() - start;

                // 如果剩余字符少于 k 个，则将剩余字符全部反转。
                if (left < k)
                {
                    reverse(s, start, s.size());
                    break;
                }

                // 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
                if( k <= left && left < 2 * k) {
                    reverse(s, start, start + k);
                    break;
                }
            }
            else
            {
                reverse(s, start, start + k);
            }
        }
        return s;
    }
};

void test(string s, int k, string expected)
{
    Solution sol;
    string result = sol.reverseStr(s, k);
    if(expected != result)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("abcdefg", 2, "bacdfeg");
    test("abcdefg", 8, "gfedcba");
    test("abcd", 2, "bacd");
    return 0;
}

