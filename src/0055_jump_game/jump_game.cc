// author: yqq
// date: 2021-06-05 16:12:16
// descriptions: https://leetcode-cn.com/problems/jump-game/

/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

 

示例 1：

输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
示例 2：

输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 

提示：

1 <= nums.length <= 3 * 104
0 <= nums[i] <= 105
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
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return true;
        }

        // 贪心算法
        int maxCover = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxCover = max(maxCover, nums[i] + i);
            if (0 == nums[i] && i == maxCover)
            {
                return false;
            }
            if (maxCover >= nums.size() - 1)
            {
                return true;
            }
        }

        return true;
    }
};

void test(vector<int> nums, bool expected)
{
    Solution sol;
    bool ret = sol.canJump(nums);
    if (ret != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({2, 3, 1, 1, 4}, true);
    test({3, 2, 1, 0, 4}, false);
    test({0}, true);
    test({3, 2, 1, 2, 0, 4}, true);
    cout << "hello world" << endl;
    return 0;
}
