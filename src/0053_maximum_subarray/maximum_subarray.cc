// author: yqq
// date: 2021-06-04 15:54:08
// descriptions: https://leetcode-cn.com/problems/maximum-subarray/

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [0]
输出：0
示例 4：

输入：nums = [-1]
输出：-1
示例 5：

输入：nums = [-100000]
输出：-100000
 

提示：

1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
 

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            int tmpSum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                tmpSum += nums[j];
                maxSum = max(tmpSum, maxSum);
            }
        }

        return maxSum;
    }
};

void test(vector<int> nums, int expected)
{
    Solution sol;
    int result = sol.maxSubArray(nums);
    if (result != expected)
    {
        cout << "FAILED" << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    test({1}, 1);
    test({0}, 0);
    test({-1}, -1);
    test({-100000}, -100000);
    cout << "hello world" << endl;
    return 0;
}
