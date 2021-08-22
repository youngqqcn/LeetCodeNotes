// author: yqq
// date: 2021-08-20 18:15:16
// descriptions: https://leetcode-cn.com/problems/target-sum
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
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：

输入：nums = [1], target = 1
输出：1
 

提示：

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/

class Solution
{
private:
    int result;
    // 1. 穷举
    void findTargetV1(vector<int>& nums, int target, int start, int sum)
    {
        if(nums.size() <= start)
        {
            if(sum == target) {
                result++;
            }
            return;
        }

        findTargetV1(nums, target, start + 1, sum + nums[start]);
        findTargetV1(nums, target, start + 1, sum - nums[start]);
    }

    // 2. 动态规划  TODO
    int finTargetV2(vector<int>& nums, int target)
    {
        // dp[i]
        return 0;
    }
public:
    int findTargetSumWays_v1(vector<int>& nums, int target)
    {
        result = 0;
        findTargetV1(nums, target, 0, 0);
        return result;
    }


    int findTargetSumWays(vector<int>& nums, int S)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (S > sum) return 0; // 此时没有方案
        if ((S + sum) % 2 == 1) return 0; // 此时没有方案
        if (S + sum < 0) return 0;

        int bagSize = (S + sum) / 2;

        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};

void test(vector<int> nums, int target, int expected)
{
    Solution sol;
    auto result = sol.findTargetSumWays(nums, target);
    if(result != expected)
    {
        cout << "FAILED: " << "expected " << expected << " got " << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,1,1,1,1}, 3, 5);
    test({1}, 1, 1);
    return 0;
}

