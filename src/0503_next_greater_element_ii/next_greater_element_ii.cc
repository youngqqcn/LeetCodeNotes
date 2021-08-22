// author: yqq
// date: 2021-08-22 16:06:11
// descriptions: https://leetcode-cn.com/problems/next-greater-element-ii
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
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），
输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，
这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数；
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。

注意: 输入数组的长度不会超过 10000。

*/


class Solution
{
public:
    // 暴力搜索
    vector<int> nextGreaterElements_v1(vector<int>& nums)
    {
        vector<int> result(nums.size(), -1);

        for(int i = 0; i < nums.size(); i++)
        {
            // 向后搜
            bool loop = true;
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i]) {
                    result[i] = nums[j];
                    loop = false;
                    break;
                }
            }

            // 如果已经找到了,则不需要继续找了
            if(!loop) {
                continue;
            }

            // 从头开始搜
            for(int j = 0; j < i; j++)
            {
                if(nums[j] > nums[i]) {
                    result[i] = nums[j];
                    break;
                }
            }
        }
        return result;
    }

    // 单调栈 + 循环数组
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int n = nums.size();
        stack<int> stk;
        vector<int> result(nums.size(), -1);

        // 2 * n - 1  ,  循环
        for(int i = 0; i < 2 * n - 1; i++)
        {
            while(!stk.empty() && nums[ stk.top()] < nums[i % n])
            {
                result[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return result;
    }
};


void test(vector<int> nums, vector<int> expected)
{
    Solution solution;
    auto result = solution.nextGreaterElements(nums);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,1}, {2,-1,2});
    test({1,2,3,4,3}, {2,3,4,-1,4});
    return 0;
}

