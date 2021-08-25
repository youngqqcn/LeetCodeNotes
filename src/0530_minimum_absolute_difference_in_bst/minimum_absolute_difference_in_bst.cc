// author: yqq
// date: 2021-08-25 11:36:01
// descriptions: https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
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

#include "../include/make_tree.h"
using namespace std;

/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 

提示：

树中至少有 2 个节点。
本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
*/


class Solution
{
private:
    vector<int> nums;
    void traverse(TreeNode* root)
    {
        if(nullptr == root) return;

        traverse(root->left);
        nums.push_back(root->val);
        traverse(root->right);
    }


    // 直接在遍历的时候计算最小（绝对值）差值
    int ndiff;
    int num;
    void traverse_v2(TreeNode* root)
    {
        if(nullptr == root) return;
        traverse_v2(root->left);
        // nums.push_back(root->val);
        ndiff = min(abs(root->val - num), ndiff);
        num = root->val;
        traverse_v2(root->right);
    }

public:
    int getMinimumDifference_v1(TreeNode* root)
    {
        // 中序遍历
        traverse(root);

        // 计算差值最小的
        int diff = INT32_MAX;
        for(int i = 1; i < nums.size(); i++)
        {
            if(abs(nums[i] - nums[i - 1]) < diff) {
                diff = abs(nums[i] - nums[i - 1]);
            }
        }
        return diff;
    }

    int getMinimumDifference(TreeNode* root)
    {
        ndiff = INT32_MAX;
        num = INT32_MAX;
        traverse_v2(root);
        return ndiff;
    }
};


void test(vector<int64_t> nums, int expected)
{
    TreeNode* root = makeTree(nums);

    Solution solution;
    auto result = solution.getMinimumDifference(root);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, NIL, 3, 2}, 1);
    return 0;
}

