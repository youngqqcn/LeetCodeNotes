// author: yqq
// date: 2021-09-16 16:32:55
// descriptions: https://leetcode-cn.com/problems/monotone-increasing-digits
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
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9

示例 2:

输入: N = 1234
输出: 1234

示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

*/

class Solution {
private:
    bool isOk(int n)
    {
        string strn = to_string(n);
        if(strn.length() == 1) return true;
        for(int i = 1; i < strn.size(); i++)
        {
            if(strn[i -1] > strn[i]){
                return false;
            }
        }
        return true;
    }
public:
    // 暴力搜索
    int monotoneIncreasingDigits_v1(int n)
    {
        for(int i = n; i >= 0; i--)
        {
            if(isOk(i)){
                return i;
            }
        }
        return 0;
    }

    static void setNine(string &s)
    {
        if(s.length() == 1) return;

        s[0] = s[0] - 1;
        for(int i = 1; i < s.size(); i++)
        {
            s[i] = '9';
        }
        return;
    }

    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        bool stop = false;
        while(!stop)
        {
            stop = !stop;
            int len = strlen(s.c_str()); // 不能直接使用 s.length() 或者 s.size()
            for(int i = 1; i < len; i++)
            {
                if(s[i-1] > s[i]) {
                    // 处理中间的两位数变一位数的情况, 例如： 10 -> 9  ,  110 -> 99
                    int pos = (i-1 > 0 && s[i-1]=='1') ? (i-2) : (i-1);
                    string s1 = s.substr(pos);
                    setNine(s1);
                    strcpy((char *)s.c_str() + pos, s1.c_str());
                    stop = !stop;
                    break;
                }
            }
        }
        return strtol(s.c_str(), nullptr, 10);
    }
};

void test(int n, int expected)
{
    Solution sol;
    int result = sol.monotoneIncreasingDigits(n);
    if(result != expected)
    {
        cout << "FAILED " << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    // cout << Solution::getNine(7) << endl;
    test(10, 9);
    test(1234, 1234);
    test(332, 299);
    test(753, 699);
    test(963856657, 899999999);
    test(120, 119);
    test(110, 99);
    return 0;
}

