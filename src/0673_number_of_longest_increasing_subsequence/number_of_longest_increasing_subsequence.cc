// author: yqq
// date: 2021-08-27 15:33:07
// descriptions: https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence
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

给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。

示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。

注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。

*/

class Solution
{
public:
    // 动态规划
    //
    //  dp[i] 表示以 nums[i]结尾的最长子序列的长度
    // count[i] 表示以nums[i] 结尾的最长子序列的个数
    int findNumberOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size() , 1);

        int maxLength = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]) {
                    if(dp[j] + 1 > dp[i]) {
                        count[i] = count[j];
                        dp[i] = dp[j] + 1;
                    }else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }

                }
            }

            if (dp[i] > maxLength) {
                maxLength = dp[i]; // 记录最长长度
            }
        }

        int result = 0;
        for(int i = 0; i < dp.size(); i++)
        {
            if(maxLength == dp[i]) {
                result += count[i];
            }
        }
        return result;
    }
};

void test(vector<int> nums, int expected)
{
    Solution solution;
    int result = solution.findNumberOfLIS(nums);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,3,5,4,7}, 2);
    test({2,2,2,2,2}, 5);
    test({1,3,5,4,7}, 2);
    test({1}, 1);
    return 0;
}

