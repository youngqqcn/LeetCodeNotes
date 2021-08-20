// author: yqq
// date: 2021-08-19 11:17:47
// descriptions: https://leetcode-cn.com/problems/increasing-subsequences
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
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

 

示例 1：

输入：nums = [4,6,7,7]
输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

示例 2：

输入：nums = [4,4,3,2,1]
输出：[[4,4]]
 

提示：

1 <= nums.length <= 15
-100 <= nums[i] <= 100

*/

class Solution
{
private:
    set<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int start)
    {
        unordered_set<int> uset;
        for(int i = start; i < nums.size(); i++)
        {
            if(uset.find(nums[i]) != uset.end()) {
                continue;
            }

            if(path.empty() || (path.size() > 0 && path.back() <= nums[i]) ) {
                uset.insert(nums[i]);

                path.push_back(nums[i]);

                if(path.size() >= 2) {
                    result.insert(path);
                }

                // 递归
                backtracking(nums, i+1);

                // 回溯
                path.pop_back();
            }
        }
    }

public:
    // 回溯法
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};

void test(vector<int> nums, set<vector<int>> expected)
{
    Solution sol;
    auto result = sol.findSubsequences(nums);
    if(result.size() != expected.size())
    {
        cout << "FAILED" << endl;
        return;
    }

    for(auto &item : result)
    {
        // set<int> s(item.begin(), item.end());
        auto it = expected.find(item);
        if(it == expected.end())
        {
            cout << "FAILED" << endl;
            return;
        }
        expected.erase(it);
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({4,6,7,7}, {{4,6},{4,6,7},{4,6,7,7},{4,7},{4,7,7},{6,7},{6,7,7},{7,7}});
    test({4,4,3,2,1}, {{4, 4}});

    return 0;
}

