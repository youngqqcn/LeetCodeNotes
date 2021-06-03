// author: yqq
// date: 2021-06-03 15:52:56
// descriptions: https://leetcode-cn.com/problems/permutations/
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
    vector<vector<int>> result;
    vector<int> vtmp;
    vector<bool> used;

private:
    void backtracking(const vector<int> &nums)
    {
        // 递归终止
        if(nums.size() == vtmp.size()){
            result.push_back(vtmp);
            return;
        }

        // 循环
        for(int i = 0; i < nums.size(); i++)
        {
            // 处理
            if(!used[i]){
                vtmp.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, 0) ;
                // 回溯
                vtmp.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        result.clear();
        vtmp.clear();
        used.resize(nums.size(), false);
        backtracking(nums, 0);
        return result;
    }
};

void test(vector<int> nums, set<vector<int>> expected)
{

    Solution sol;
    vector<vector<int>> result = sol.permute(nums);
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
    cout << "hello world" << endl;
    return 0;
}
