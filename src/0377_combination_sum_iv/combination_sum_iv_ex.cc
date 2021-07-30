// author: yqq
// date: 2021-07-30 17:38:19
// descriptions: https://leetcode-cn.com/problems/combination-sum-iv
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
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

 

示例 1：

输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。
示例 2：

输入：nums = [9], target = 3
输出：0
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 1000
nums 中的所有元素 互不相同
1 <= target <= 1000

进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件
*/


class Solution {
public:
    // 进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件
    //
    //  如果有负数, 可能导致个数有无限多个
    //
    //  如果有负数, i - nums[j] 可能大于 i,
    //  dp[i] = acculate(dp[i - nums[j]]) + x;
    //  两遍遍历dp数组:
    //    第1遍: 从前往后, 只取正数
    //    第2遍: 从后往前, 只取负数

    // dp[i] 表示target为 i时的满足题目条件组合的个数
    // dp[i] = acculate(dp[i - nums[j]]) + x;   其中 0 <= j < nums.size(); 如果 i 在 nums中则, x=1, 否则 x=0
    // dp[0] = 1;
    int combinationSum4(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        // 防止中途整数溢出, 所以使用uint64_t
        vector<uint64_t> dp(target + 1, 0);

        //  可以处理 nums[j] == i 的情况
        dp[0] = 1;

        for(int i = 1; i < dp.size(); i++)
        {
            for(int j = 0; j < nums.size() && nums[j] <= i; j++)
            {
                dp[i] +=  dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};


void test(vector<int> nums, int target, int expected)
{
    Solution sol;
    auto result = sol.combinationSum4(nums, target);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,3, -1}, 4, 7);
    test({1,2,3}, 4, 7);
    test({9}, 3, 0);
    test({3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}, 1, 0);
    test({10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111}, 999, 1);
    return 0;
}

