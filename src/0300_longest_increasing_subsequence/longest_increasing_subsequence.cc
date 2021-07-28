// author: yqq
// date: 2021-07-27 17:45:10
// descriptions: https://leetcode-cn.com/problems/longest-increasing-subsequence
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
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

 
示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1
 

提示：

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
 

进阶：

你可以设计时间复杂度为 O(n^2) 的解决方案吗？
你能将算法的时间复杂度降低到 O(n log(n)) 吗?

*/

class Solution
{
private:
    int maxLen;
    int curMaxLen;
    // 超时
    void backtracking(vector<int> &nums, int startIdx, int minNum, int &curMaxLen)
    {
        for (int i = startIdx; i < nums.size(); i++)
        {
            if (nums[i] > minNum)
            {
                curMaxLen += 1;
                if (maxLen < curMaxLen)
                {
                    maxLen = curMaxLen;
                }

                int idx = i + 1;
                while (idx < nums.size() && nums[idx] <= nums[i])
                {
                    idx++;
                }

                backtracking(nums, idx, nums[i], curMaxLen);

                // 回溯
                curMaxLen -= 1;
            }
        }
    }

public:
    // 回溯法, 超时
    // int lengthOfLIS(vector<int> &nums)
    // {
    //     maxLen = INT32_MIN;
    //     curMaxLen = 0;
    //     backtracking(nums, 0, INT32_MIN, curMaxLen);
    //     return maxLen;
    // }


    // https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
    //
    //
    //  定义 dp[i] 为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度，注意 nums[i] 必须被选取。
    //  dp[i]=max(dp[j])+1,   其中0≤j<i 且 num[j]<num[i]
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            int maxj = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && dp[j] > maxj) {
                    maxj = dp[j];
                }
            }
            dp[i] = maxj + 1;

            result = max(dp[i], result);
        }
        return result;
    }

};

void test(vector<int> nums, int expected)
{
    Solution sol;
    auto result = sol.lengthOfLIS(nums);
    if (result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({10, 9, 2, 5, 3, 7, 101, 18}, 4);
    test({0, 1, 0, 3, 2, 3}, 4);
    test({7, 7, 7, 7, 7, 7, 7}, 1);
    return 0;
}
