// author: yqq
// date: 2021-08-26 17:56:30
// descriptions: https://leetcode-cn.com/problems/maximum-binary-tree
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
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。

 

示例 1：
        6
      /   \
     3     5
      \    /
       2  0
        \
         1


输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。

示例 2：

     3
      \
       2
        \
         1


输入：nums = [3,2,1]
输出：[3,null,2,null,1]
 

提示：

1 <= nums.length <= 1000
0 <= nums[i] <= 1000
nums 中的所有整数 互不相同
*/


class Solution
{
private:
    // 处理 nums[start, end ) 的元素,  注意： 左闭右开
    TreeNode* construct(vector<int>& nums, int start, int end)
    {
        // 因为是“左闭右开”， 所以 start 不能等于 end
        if(start >= end || start < 0 || start >= nums.size() || end < 0 || end > nums.size())
        {
            return nullptr;
        }

        auto maxValueIt = max_element(nums.begin()+start, nums.begin() + end);
        int maxValueIdx = maxValueIt - nums.begin() ;
        int maxValue = *maxValueIt;

        TreeNode* root = new TreeNode(maxValue);
        root->left = construct(nums, start, maxValueIdx );
        root->right = construct(nums, maxValueIdx + 1, end);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return construct(nums, 0, nums.size() );
    }
};


void test(vector<int> nums)
{
    Solution sol;
    TreeNode* root = sol.constructMaximumBinaryTree(nums);
    if(nullptr == root) {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({3,2,1,6,0,5});
    test({3,2,1});
    test({1,2,3});

    return 0;
}

