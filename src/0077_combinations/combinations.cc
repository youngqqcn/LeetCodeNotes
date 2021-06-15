// author: yqq
// date: 2021-06-15 18:24:19
// descriptions: https://leetcode-cn.com/problems/combinations/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> nums;
public:
    void backtracking(int startIndex, int n, int k)
    {
        // 递归终止
        if (nums.size() == k)
        {
            result.push_back(nums);
            return;
        }

        // 遍历
        for (int j = startIndex; j <= n; j++)
        {
            nums.push_back(j);
            backtracking(j + 1, n, k);
            // 回溯
            nums.pop_back();
        }
    }

    // 回溯法
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        nums.clear();

        backtracking(1, n, k);
        return result;
    }
};

void test(int n, int k, set<vector<int>> expected)
{
    Solution sol;
    auto result = sol.combine(n, k);

    if (result.size() != expected.size())
    {
        cout << "FAILED" << endl;
        return;
    }

    for (auto v : result)
    {
        auto it = expected.find(v);
        if (it == expected.end())
        {
            cout << "FAILED" << endl;
        }
        expected.erase(it);
    }

    cout << "PASSED" << endl;
}

int main()
{
    //   [2,4],
    //   [3,4],
    //   [2,3],
    //   [1,2],
    //   [1,3],
    //   [1,4],
    test(4, 2, {{2, 4}, {3, 4}, {2, 3}, {1, 2}, {1, 3}, {1, 4}});
    cout << "hello world" << endl;
    return 0;
}
