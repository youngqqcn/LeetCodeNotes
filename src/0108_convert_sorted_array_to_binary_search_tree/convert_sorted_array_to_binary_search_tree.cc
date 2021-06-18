// author: yqq
// date: 2021-06-18 16:22:23
// descriptions:  https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
#include "../include/make_tree.h"
using namespace std;

/*
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。


示例:
       0
     /  \
   -3    9
   /    /
 10    5

输入：nums = [-10,-3,0,5,9]
输出：[0,-3,9,-10,null,5]
解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：

    0
   /  \
-10    5
  \     \
  -3     9

示例2:

   3     1
  /       \
 1         3

输入：nums = [1,3]
输出：[3,1]
解释：[1,3] 和 [3,1] 都是高度平衡二叉搜索树。
 

提示：
1 <= nums.length <= 10^4
-104 <= nums[i] <= 10^4
nums 按 严格递增 顺序排列

*/


// 思路:
//     函数F(nums):
//       1. mid = nums.size() / 2   取 mid作为root
//       2. 递归   root.left = F(nums[0: mid-1]),   root.right = F(nums[mid+1: ])

class Solution {
private:
#if 0
    TreeNode* build(vector<int> nums)
    {
        if(nums.empty()) return nullptr;

        int mid  = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> leftItems(nums.begin(), nums.begin() + mid);
        vector<int> rightItems(nums.begin() + mid + 1 , nums.end());
        root->left = build(leftItems);
        root->right = build(rightItems);
        return root;
    }
#endif

    // 使用索引提高性能
    TreeNode* build(vector<int> &nums, int startIndex, int endIndex)
    {
        if(startIndex > endIndex) return nullptr;

        int mid  = (endIndex + startIndex) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, startIndex, mid - 1 );
        root->right = build(nums, mid + 1, endIndex);
        return root;
    }

    // TODO: 使用迭代
    TreeNode* build_v2(vector<int> &nums, int startIndex, int endIndex)
    {
        return nullptr;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // vector<int> tmp(nums.begin(), nums.end());
        // return build(tmp);
        return build(nums, 0, nums.size() - 1);
    }
};



void test(vector<int> nums )
{
    Solution sol;
    TreeNode *root= sol.sortedArrayToBST(nums);
    if(root == nullptr){
        cout << "FAILED" << endl;
    }
}

int main()
{
    test({-10,-3,0,5,9});
    // test({1,3});
    cout << "hello world" << endl;
    return 0;
}

