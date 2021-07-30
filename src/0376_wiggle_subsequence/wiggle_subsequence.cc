// author: yqq
// date: 2021-07-30 14:59:48
// descriptions: https://leetcode-cn.com/problems/wiggle-subsequence
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

如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。

例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。

相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。

 

示例 1：

输入：nums = [1,7,4,9,2,5]
输出：6
解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
示例 2：

输入：nums = [1,17,5,10,13,15,10,5,16,8]
输出：7
解释：这个序列包含几个长度为 7 摆动序列。
其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
示例 3：

输入：nums = [1,2,3,4,5,6,7,8,9]
输出：2
 

提示：

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
 

进阶：你能否用 O(n) 时间复杂度完成此题?
*/

class Solution
{
public:

    int maxLen;
    void backtracking(vector<int> &nums, int n, int startIdx, bool symbol, int curMaxLen)
    {
        for(int i = startIdx; i < nums.size(); i++)
        {
            if(nums[i] != n && symbol == (nums[i] - n > 0) ) {
                maxLen = max(maxLen, curMaxLen + 1);
                backtracking(nums, nums[i], i+1, !symbol, curMaxLen + 1);
            }
        }
    }


    // 暴力搜索(超时)
    int wiggleMaxLength_v1(vector<int>& nums)
    {
        maxLen = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] != nums[i])
                {
                    maxLen = max(2, maxLen);
                    bool symbol = nums[j] - nums[i] > 0;
                    backtracking(nums, nums[j], j+1, !symbol, 2);
                    // 回溯
                }
            }
        }

        return maxLen;
    }

    // 动态规划
    // dp[i][s] 表示[0..i] 最长摆动子序列长度   s==0: 表示nums[i]与nums[j]之差为负数,  s==1表示正数
    // dp[i][0] = max(dp[j][1]) + x  , 如果 nums[i] == nums[i-1], 则x为0;  其中  0 <= j < i
    // dp[i][1] = max(dp[j][0]) + x  , 如果 nums[i] == nums[i-1], 则x为0;  其中  0 <= j < i
    //
    // 最终结果: max(dp[i][1], dp[i][0])
    int wiggleMaxLength_v2(vector<int>& nums)
    {
        if(nums.size() < 2) return 1;

        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][0] = 1;
        dp[0][1] = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] - nums[j] < 0) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }else if(nums[i] - nums[j] > 0) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }else {
                    dp[i][0] = max(dp[i][0], dp[j][0] );
                    dp[i][1] = max(dp[i][1], dp[j][1] );
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }

    // 贪心法
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() <= 1) return nums.size();
        int curDiff = 0; // 当前一对差值
        int preDiff = 0; // 前一对差值
        int result = 1;  // 记录峰值个数，序列默认序列最右边有一个峰值
        for (int i = 0; i < nums.size() - 1; i++)
        {
            curDiff = nums[i + 1] - nums[i];
            // 出现峰值
            if ((curDiff > 0 && preDiff <= 0) || (preDiff >= 0 && curDiff < 0)) {
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};

void test(vector<int> nums, int expected)
{
    Solution sol;
    auto result = sol.wiggleMaxLength(nums);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,7,4,9,2,5}, 6);
    test({1,17,5,10,13,15,10,5,16,8}, 7);
    test({1,2,3,4,5,6,7,8,9}, 2);
    test({81}, 1);
    test({33,53,12,64,50,41,45,21,97,35,47,92,39,0,93,55,40,46,69,42,6,95,51,68,72,9,32,84,34,64,6,2,26,98,3,43,30,60,3,68,82,9,97,19,27,98,99,4,30,96,37,9,78,43,64,4,65,30,84,90,87,64,18,50,60,1,40,32,48,50,76,100,57,29,63,53,46,57,93,98,42,80,82,9,41,55,69,84,82,79,30,79,18,97,67,23,52,38,74,15}, 67);
    return 0;
}

