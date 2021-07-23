// author: yqq
// date: 2021-07-23 11:43:10
// descriptions: https://leetcode-cn.com/problems/happy-number/
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
#include <cmath>
using namespace std;

/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 true ；不是，则返回 false 。

 

示例 1：

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1


示例 2：

输入：n = 2
输出：false
 

提示：

1 <= n <= 2^31 - 1

*/

class Solution {
public:
    int calcSum(int n)
    {
        char buf[100] = {0};
        sprintf(buf, "%d", n);
        int sum = 0;
        for(int i = 0; i < strlen(buf); i++)
        {
            sum += pow(int(buf[i] - '0'), 2);
        }
        return sum;
    }

    bool isHappy(int n)
    {
        if(n < 2) return true;
        unordered_set<int> nums;
        nums.insert(n);

        int sum = 0;
        while(true)
        {
            sum = calcSum(n);
            if(1 == sum) return true;
            if(nums.find(sum) != nums.end()) {
                break;
            }

            nums.insert(sum);
            n = sum;
        }
        return false;
    }
};

void test(int n , bool expected)
{
    Solution sol;
    auto result = sol.isHappy(n);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout  << "PASSED" << endl;
}

int main()
{
    test(19, true);
    test(2, false);
    test(21, false);
    test(22, false);
    test(51, false);
    test(5360, true);
    test(1111111, true);
    test(1999999999, false);
    test(2026119321, false);
    test(2071510243, true);

    return 0;
}

