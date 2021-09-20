// author: yqq
// date: 2021-09-19 18:21:31
// descriptions: https://leetcode-cn.com/problems/valid-mountain-array
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
给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。

让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

1. arr.length >= 3
2. 在 0 < i < arr.length - 1 条件下，存在 i 使得：
    a)  arr[0] < arr[1] < ... arr[i-1] < arr[i]
    b)  arr[i] > arr[i+1] > ... > arr[arr.length - 1]


示例 1：

输入：arr = [2,1]
输出：false
示例 2：

输入：arr = [3,5,5]
输出：false
示例 3：

输入：arr = [0,3,2,1]
输出：true
 

提示：

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^4

*/

class Solution {
public:
    bool validMountainArray(vector<int>& arr)
    {
        if( arr.size() < 3) {
            return false;
        }

        int i = 1;
        bool flagIncrease = false; // 上升
        bool flagDecrease = false; // 下降
        for(; i < arr.size() && arr[i-1] < arr[i]; i++)
        {
            flagIncrease = true;
        }

        for(; i < arr.size() && arr[i-1] > arr[i]; i++)
        {
            flagDecrease = true;
        }

        return i == arr.size() && flagIncrease && flagDecrease;
    }
};

void test(vector<int> arr, bool expected)
{
    Solution sol;
    bool result = sol.validMountainArray(arr);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({2, 1}, false);
    test({3, 5, 5}, false);
    test({0, 3, 2, 1}, true);
    test({0,1,2,3,4,5,6,7,8,9}, false);
    test({9,8,7,6,5,4,3,2,1,0}, false);
    return 0;
}

