// author: yqq
// date: 2021-09-15 15:44:50
// descriptions: https://leetcode-cn.com/problems/binary-search
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

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

*/

class Solution {
private:
    int binarySearch(const vector<int>& nums, int start, int end, int target)
    {
        if(start > end) return -1;

        int mid = (start + end) / 2;
        if(target == nums[mid]) return mid;

        if(target < nums[mid]) {
            return binarySearch(nums, start, mid - 1, target);
        }
        return binarySearch(nums, mid + 1, end, target);
    }
public:
    int search(vector<int>& nums, int target)
    {
        return binarySearch(nums, 0, nums.size() -1 , target);
    }
};


void test(vector<int> nums, int target, int expected)
{
    Solution sol;
    int result = sol.search(nums, target);
    if(result != expected) {
        cout << "FAILED" << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({-1,0,3,5,9,12}, 2, -1);
    test({1, 2, 3, 4, 5, 6, 7}, 7, 6);
    return 0;
}

