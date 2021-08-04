// author: yqq
// date: 2021-08-04 10:17:11
// descriptions: https://leetcode-cn.com/problems/partition-equal-subset-sum
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
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。


示例 1：

输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：

输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution
{
public:
    bool canPartition_v1(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 如果总和是奇数, 则不能分割
        if((sum & 1) == 1) {
            return false;
        }
        int target = sum / 2;

        // 01背包问题:  从nums取n个数, 组成target, 能否组成
        // 方法1: 回溯法
        // 方法2: 动态规划
        //
        // dp[i] 表示是否可以组成 target为 i ,  true: 可以组成 , false:不可以组成
        // dp[i] =  dp[i] || dp[ target - nums[j] ]  ,  0 <= j < nums.size()
        vector<bool> dp(target + 1, false);
        unordered_map<int, set<int>>  usedmap;
        dp[0] = true;
        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 0; j < nums.size() && !dp[i] && nums[j] <= i ; j++)
            {
                set<int>& preSet = usedmap[i - nums[j]];
                if (preSet.end() == preSet.find(j) && dp[ i - nums[j]]) {
                    dp[i] = true;
                    usedmap[i].insert( preSet.begin(), preSet.end());
                    usedmap[i].insert(j);
                    break;
                }
            }
        }
        return dp[target];
    }

    // 01背包: 动态规划优化,    如何确保物品只被使用一次
    bool canPartition(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 如果总和是奇数, 则不能分割
        if((sum & 1) == 1) {
            return false;
        }
        int target = sum / 2;

        // dp[i] 背包总容量i, 最大可以凑成i的子集总和为dp[i]
        // 物品 nums[j] 重量是nums[j] 价值也是nums[j]
        // dp[i] = max(dp[i - nums[j]] + nums[j] , dp[i])
        vector<int> dp(target + 1, 0);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // 这里是倒序, 这是个技巧, 保证了物品只被使用一次
            for(int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j - nums[i]] + nums[i], dp[j]);
            }
        }
        return dp[target] == target;
    }
};

void test(vector<int> nums, bool expected)
{
    Solution sol;
    if(expected != sol.canPartition(nums))
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,5,11,5}, true);
    // test({1,2,3,5}, false);
    // test({3,3,3,4,5}, true);
    // test({14,9,8,4,3,2}, true);
    // test({1,2,5}, false);
    // test({2,2,3,5}, false);
    return 0;
}

