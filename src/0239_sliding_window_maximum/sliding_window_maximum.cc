// author: yqq
// date: 2021-07-26 18:25:29
// descriptions: https://leetcode-cn.com/problems/sliding-window-maximum
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
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


示例 2：

输入：nums = [1], k = 1
输出：[1]
示例 3：

输入：nums = [1,-1], k = 1
输出：[1,-1]
示例 4：

输入：nums = [9,11], k = 2
输出：[11]
示例 5：

输入：nums = [4,-2], k = 2
输出：[4]
 

提示：

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

*/


class Solution {
public:
    // 暴力方法, leetcode超时
    vector<int> maxSlidingWindow_v2(vector<int>& nums, int k)
    {
        vector<int> result;
        int startIdx = 0;
        int endIdx = k;
        for(;;)
        {
            if(endIdx > nums.size()) break;
            result.push_back(*max_element(nums.begin()+startIdx, nums.begin() + endIdx));
            startIdx++;
            endIdx++;
        }
        return result;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {

    }
};

void test(vector<int> nums, int k, multiset<int> expected)
{
    Solution sol;
    auto result = sol.maxSlidingWindow(nums, k);
    if(result.size() != expected.size())
    {
        goto failed;
    }

    for(auto item : result)
    {
        auto it = expected.find(item) ;
        if(it == expected.end()) {
            goto failed;
        }
        expected.erase(it);
    }

    if(!expected.empty()) {
        goto failed;
    }

    cout << "PASSED" << endl;
    return;

failed:
    cout << "FAILED" << endl;
    return;
}

int main()
{
    test({1,3,-1,-3,5,3,6,7}, 3, {3,3,5,5,6,7});
    test({1}, 1, {1});
    test({1, -1}, 1, {1, -1});
    test({9, 11}, 2, {11});
    test({4, -2}, 2, {4});
    return 0;
}

