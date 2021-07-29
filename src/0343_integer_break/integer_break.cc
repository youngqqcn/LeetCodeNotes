// author: yqq
// date: 2021-07-29 17:13:04
// descriptions: https://leetcode-cn.com/problems/integer-break
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
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1


示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

*/



/*


整数 i 可以分解为  j  和  i - j

定义: dp[i] 表示 整数 i 可以分解的整数最大乘积

递推公式:  dp[i] = max(j * max(dp[i - j], i - j))  , 其中  1 <= j < i

0 : 1
1 : 1
2 :
    1  (1)  --> 1                            那么  dp[2] = 1
3 :
    1  (2)  -->  1 * max(dp[2], 2) --> 2     那么  dp[3] = 2

4:
    1  (3)  -->  1 * max(dp[3], 3) --> 3
    2  (2)  -->  1 * max(dp[2], 2) --> 4     那么  dp[4] = 4

5:
    1  (4) --> 1 * max(dp[4], 4) --> 4
    2  (3) --> 2 * max(dp[3], 3) --> 6
    3  (2) --> 3 * max(dp[2], 2) --> 6       那么  dp[5] = 6

6:
    1  (5) --> 1 * max(dp[5], 5) --> 6
    2  (4) --> 2 * max(dp[4], 4) --> 8       那么  dp[6] = 8
    3  (3) --> 3 * max(dp[3], 3) --> 6

*/



class Solution {
public:
    int integerBreak(int n)
    {
        if(n <= 2) return 1;

        vector<int>  dp(n + 1, INT32_MIN);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                dp[i] = max(j * max(dp[i - j], i - j),  dp[i]);
            }
        }
        return dp[n];
    }
};


void test(int n, int expected)
{
    Solution sol;
    auto result = sol.integerBreak(n);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test(2, 1);
    test(9, 27);
    test(10, 36);
    return 0;
}

