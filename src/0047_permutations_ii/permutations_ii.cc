// author: yqq
// date: 2021-06-03 17:15:43
// descriptions: https://leetcode-cn.com/problems/permutations-ii/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

class Solution
{
private:
    // set<vector<int>> result; // 用set也可以
    vector<vector<int>> result;
    vector<int> vtmp;
    vector<bool> used;

private:
    void backtracking(const vector<int> &nums)
    {
        // 递归终止
        if(nums.size() == vtmp.size()){
            // result.insert(vtmp);
            result.push_back(vtmp);
            return;
        }

        // 循环
        for(int i = 0; i < nums.size(); i++)
        {
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if(i > 0 && nums[i] == nums[i - 1] && false == used[i - 1] ){
                continue;
            }

            // 处理
            if(!used[i]){
                vtmp.push_back(nums[i]);
                used[i] = true;
                backtracking(nums) ;
                // 回溯
                vtmp.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        result.clear();
        vtmp.clear();
        used.resize(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums);
        return  result; // move(vector<vector<int>>(result.begin(), result.end()));
    }
};

void test(vector<int> nums, set<vector<int>> expected)
{

    Solution sol;
    vector<vector<int>> result = sol.permuteUnique(nums);
    if (result.size() != expected.size())
    {
        cout << "FAILED" << endl;
    }
    else
    {
        for (auto &item : result)
        {
            if (expected.find(item) == expected.end())
            {
                cout << "FAILED" << endl;
                return;
            }
            expected.erase(item);
        }
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({1, 2, 3}, {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}});
    test({0, 1}, {{0, 1}, {1, 0}});
    test({1}, {{1}});
    test({1,1,2}, {{1,1,2}, {1,2,1}, {2,1,1}});
    cout << "hello world" << endl;
    return 0;
}
