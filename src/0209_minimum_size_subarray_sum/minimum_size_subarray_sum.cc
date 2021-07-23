// author: yqq
// date: 2021-07-23 17:02:15
// descriptions: https://leetcode-cn.com/problems/minimum-size-subarray-sum/
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
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。


示例 2：

输入：target = 4, nums = [1,4,4]
输出：1

示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 
提示：

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 105
 

进阶：

如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

*/

class Solution {
public:
    // 暴力搜索 , 时间复杂度  O(n^2)
    int minSubArrayLen_v1(int target, vector<int>& nums)
    {
        if(target > accumulate(nums.begin(), nums.end(), 0) )
        {
            return 0;
        }

        if(find(nums.begin(), nums.end(), target) !=  nums.end()) {
            return 1;
        }

        int minLen = nums.size() + 1;
        for(int slow = 0; slow < nums.size(); slow++)
        {
            int sum = 0;
            for(int fast = slow; fast < nums.size(); fast++)
            {
                sum += nums[fast];
                if( sum >= target )
                {
                    minLen = min(fast - slow + 1, minLen);
                    if(1 == minLen ) return 1;
                    break;
                }
            }
        }
        return minLen;
    }

    // 滑动窗口
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int minLen = nums.size() + 1;
        int slow = 0, fast = 0, sum = 0;
        for(;fast < nums.size() && slow < nums.size(); )
        {
            sum += nums[fast];
            if(sum >= target){
                // 移动slow, 直到sum小于target为止
                while(sum >= target && slow <= fast) {
                    minLen = min(minLen, fast - slow + 1);
                    if(1  == minLen) return minLen;
                    sum -= nums[slow++];
                }
            }
            fast++;
        }
        return (minLen > nums.size()) ? (0): (minLen);
    }

};

void test(vector<int> nums, int target, int expected)
{
    Solution sol;
    auto result = sol.minSubArrayLen(target, nums);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({2,3,1,2,4,3}, 7, 2);
    test({1,4,4}, 4, 1);
    test({1,1,1,1,1,1,1,1}, 11, 0);
    test({1,1,1,1,7}, 7, 1);

    return 0;
}

