// author: yqq
// date: 2021-06-01 10:55:02
// descriptions: https://leetcode-cn.com/problems/combination-sum-ii/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

注意：解集不能包含重复的组合。 

 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]
 

提示:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

#if 0
class Solution
{
private:
    void combination(vector<int> &candidates,
                     int target, int sum,
                     vector<int> &nums, set<vector<int>> &result, int startIndex)
    {
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (sum + candidates[i] == target)
            {
                vector<int> tmp(nums.begin(), nums.end());
                tmp.push_back(candidates[i]);
                sort(tmp.begin(), tmp.end());
                result.insert(tmp);

                // 如果没有对candidates进行过排序, 这里不能直接return, 应该继续向后查找, 否则会漏掉组合
                return; // 因为实现对candidates进行了排序,所以后面的数大于等于当前数,
            }
            else if (sum + candidates[i] > target)
            {
                // continue; // 如果没有对candidates进行过排序, 则应继续向后查找
                // 因为事先对candidates进行了排序, 所以后面的数会当前数大, 不必在继续了
                return;
            }
            else if (sum + candidates[i] < target)
            {
                int n = candidates[i];
                nums.push_back(n);
                combination(candidates, target, sum + candidates[i], nums, result, i+1); // i+1 因为一个元素只能用一次
                nums.pop_back(); // 回溯
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> nums;
        set<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        combination(candidates, target, 0, nums, result, 0);
        return vector<vector<int>>(result.begin(), result.end());
    }
};

#endif

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // 要对同一树层使用过的元素进行跳过
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i + 1); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return result;
    }
};


void test(vector<int> candidates, int target, set<vector<int>> expected)
{
    Solution sol;
    auto result = sol.combinationSum2(candidates, target);

    if (result.size() != expected.size())
    {
        cout << "FAILED" << endl;
        return;
    }
    for (auto v : result)
    {
        if (expected.find(v) == expected.end())
        {
            cout << "FAILED" << endl;
            return;
        }
        expected.erase(v); // 防止重复
    }
    cout << "PASSED" << endl;
}

int main()
{

    test({10,1,2,7,6,1,5}, 8, {{1, 7}, {1, 2, 5}, {2, 6}, {1, 1, 6}});
    cout << "hello world" << endl;
    return 0;
}

