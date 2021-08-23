// author: yqq
// date: 2021-08-23 15:53:05
// descriptions: https://leetcode-cn.com/problems/fibonacci-number
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
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1
给你 n ，请计算 F(n) 。


示例 1：
输入：2
输出：1
解释：F(2) = F(1) + F(0) = 1 + 0 = 1

示例 2：
输入：3
输出：2
解释：F(3) = F(2) + F(1) = 1 + 1 = 2

示例 3：
输入：4
输出：3
解释：F(4) = F(3) + F(2) = 2 + 1 = 3

提示：

0 <= n <= 30

*/

class Solution
{
public:
    // 递归
    int fib_v1(int n)
    {
        if(0 == n) return 0;
        if(1 == n || 2 == n) return 1;
        return fib_v1(n - 1) + fib_v1(n - 2);
    }

    // 迭代
    int fib(int n)
    {
        int a = 0, b = 1;
        int tmp = 0;
        for(int i = 0; i < n; i++)
        {
            tmp = a;
            a = a + b;
            b = tmp;
        }
        return a;
    }

};

void test(int n, int expected)
{
    Solution sol;
    int result = sol.fib(n);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test(0, 0);
    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 3);

    return 0;
}

