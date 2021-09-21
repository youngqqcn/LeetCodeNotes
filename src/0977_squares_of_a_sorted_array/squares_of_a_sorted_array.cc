// author: yqq
// date: 2021-09-21 16:34:59
// descriptions: https://leetcode-cn.com/problems/squares-of-a-sorted-array
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
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

示例 1：

输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：

输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
 

提示：

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums 已按 非递减顺序 排序
 

进阶：

请你设计时间复杂度为 O(n) 的算法解决本问题


*/

class Solution {
public:
    // 单调栈 
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> result;

        stack<int> stk;
        for(int i = 0; i < nums.size(); i++)
        {
            int square = pow(nums[i], 2);
            while(!stk.empty() && stk.top() < square)
            {
                result.push_back(stk.top());
                stk.pop();
            }
            stk.push(square);
        }

        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};


void test(vector<int> nums, vector<int> expected)
{
    Solution sol;
    auto  result = sol.sortedSquares(nums);
    if(!std::equal(result.begin(), result.end(), expected.begin()))
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({-4,-1,0,3,10}, {0,1,9,16,100});
    test({-7,-3,2,3,11}, {4,9,9,49,121});
    return 0;
}

