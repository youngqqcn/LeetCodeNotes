// author: yqq
// date: 2021-06-16 11:06:37
// descriptions: https://leetcode-cn.com/problems/subsets-ii/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;


/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。



示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/


class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;


    /*
        以 [1, 2, 2, 3] 为例, 需要对nums进行排序, 这样相同的元素会相邻

                 1
               /   \
              2     2[前面已经用过]
             / \     \
            2   3     3[重复了]
    */

    void backtracking(const vector<int> &nums, int startIndex)
    {
        // 直接收集path
        result.push_back(path);

        for(int i = startIndex; i < nums.size(); i++) // 优化
        {
            // 需要对nums进行排序, 这样相同的元素会相邻
            // used[i - 1] == fasle  说明前面那个2已经在做过非叶子节点, 当前这个2不能再做非叶子节点了
            // 如果used[i - 1] == true  说明此时处于前面那个下面, 即  [1, 2, 2] 这个路径
            if( i > 0 && nums[i] == nums[i-1] && used[i-1] == false) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, i+1);

            used[i] = false;
            path.pop_back(); // 回溯
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        result.clear();
        path.clear();
        used.assign(nums.size(), false);
        sort(nums.begin(), nums.end()); // 排序

        backtracking(nums, 0);
        return result;
    }
};


void test(vector<int> nums, set<vector<int>> expected)
{
    Solution sol;
    auto result =  sol.subsetsWithDup(nums);
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
    // test({1,2,3}, {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}});
    // test({0}, {{}, {0}});
    test({1,2,2}, {{},{1},{1,2},{1,2,2},{2},{2,2}});

    cout << "hello world" << endl;
    return 0;
}