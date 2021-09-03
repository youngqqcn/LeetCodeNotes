// author: yqq
// date: 2021-08-30 16:40:43
// descriptions: https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
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
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，
都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]]
就是连续递增子序列。

 

示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。

示例 2：

输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。
 

提示：

1 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
*/


class Solution
{
public:
    // 贪心
    int findLengthOfLCIS(vector<int>& nums)
    {
        int result = 1;
        int tempLen = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1]) {
                tempLen++;
                result = max(result, tempLen);
            } else {
                tempLen = 1;
            }
        }
        return result;
    }
};

void test(vector<int> nums, int expected)
{
    Solution sol;
    int result = sol.findLengthOfLCIS(nums);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,3,5,4,7}, 3);
    test({2,2,2,2,2}, 1);
    test({1,3,5,4,2,3,4,5}, 4);
    return 0;
}

