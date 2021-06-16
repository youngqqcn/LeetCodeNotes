// author: yqq
// date: 2021-06-16 10:16:27
// descriptions: https://leetcode-cn.com/problems/subsets/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;


/*

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同

*/


// 思路:
// 1.可以转换为 组合问题: n个元素中取k , 其中k属于[0, n]
// 2.遍历整棵树, 收集每个节点(包括根节点, 叶子节点)

class SolutionV1 {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(const vector<int> &nums, int k , int startIndex)
    {
        if(k == path.size()) {
            result.push_back(path);
            return;
        }

        // for(int i = startIndex; i < nums.size() ; i++) // 未优化
        for(int i = startIndex; i < nums.size() - (k - path.size()) + 1; i++) // 优化
        {
            path.push_back(nums[i]);
            backtracking(nums, k, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        result.clear();
        path.clear();

        for(int k = 0; k <= nums.size(); k++)
        {
            backtracking(nums, k, 0);
        }
        return result;
    }
};


class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(const vector<int> &nums, int startIndex)
    {
        // 直接收集path
        result.push_back(path);

        for(int i = startIndex; i < nums.size(); i++) // 优化
        {
            path.push_back(nums[i]);
            backtracking(nums, i+1);
            path.pop_back(); // 回溯
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        result.clear();
        path.clear();

        backtracking(nums, 0);
        return result;
    }
};


void test(vector<int> nums, set<vector<int>> expected)
{
    Solution sol;
    auto result =  sol.subsets(nums);
    if(result.size() != expected.size()){
        cout << "FAILED" << endl;
        return;
    }

    for(auto item : result)
    {
        auto it = expected.find(item) ;
        if(it== expected.end()){
            cout << "FAILED" << endl;
            return;
        }else{
            expected.erase(it);
        }
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,3}, {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}});
    test({0}, {{}, {0}});
    cout << "hello world" << endl;
    return 0;
}

