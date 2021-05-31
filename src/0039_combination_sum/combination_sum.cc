// author: yqq
// date: 2021-05-31 21:15:48
// descriptions: https://leetcode-cn.com/problems/combination-sum/
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
private:
    void combination(vector<int> &candidates,
                     int target, int sum,
                     vector<int> &nums, set<vector<int>> &result)
    {
        for (int i = 0; i < candidates.size(); i++)
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
                nums.push_back(candidates[i]);
                combination(candidates, target, sum + candidates[i], nums, result);
                nums.pop_back(); // 回溯
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> nums;
        set<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        combination(candidates, target, 0, nums, result);
        return vector<vector<int>>(result.begin(), result.end());
    }
};

void test(vector<int> candidates, int target, set<vector<int>> expected)
{
    Solution sol;
    auto result = sol.combinationSum(candidates, target);

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
    test({2, 3, 6, 7}, 7, {{7}, {2, 2, 3}});
    test({2, 3, 5}, 8, {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}});
    test({2, 7, 6, 3, 5, 1}, 9, {{1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 2}, {1, 1, 1, 1, 1, 1, 3}, {1, 1, 1, 1, 1, 2, 2}, {1, 1, 1, 1, 2, 3}, {1, 1, 1, 1, 5}, {1, 1, 1, 2, 2, 2}, {1, 1, 1, 3, 3}, {1, 1, 1, 6}, {1, 1, 2, 2, 3}, {1, 1, 2, 5}, {1, 1, 7}, {1, 2, 2, 2, 2}, {1, 2, 3, 3}, {1, 2, 6}, {1, 3, 5}, {2, 2, 2, 3}, {2, 2, 5}, {2, 7}, {3, 3, 3}, {3, 6}});
    // cout << "hello world" << endl;
    return 0;
}
