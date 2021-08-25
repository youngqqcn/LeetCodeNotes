// author: yqq
// date: 2021-08-25 18:15:25
// descriptions: https://leetcode-cn.com/problems/merge-two-binary-trees
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
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，
那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
    Tree 1                     Tree 2

          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
输出:
合并后的树:
         3
        / \
       4   5
      / \   \
     5   4   7
注意: 合并必须从两个树的根节点开始。

*/


class Solution
{
private:
    TreeNode* merge(TreeNode* root1, TreeNode* root2)
    {
        if(nullptr == root1 || nullptr == root2) {
            return (nullptr == root1) ? (root2) : (root1);
        }

        if(nullptr != root1 && nullptr != root2) {
            root1->val += root2->val;
        }

        root1->left = merge(root1->left, root2->left);
        root1->right = merge(root1->right, root2->right);
        return root1;
    }
    
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        return merge(root1, root2);
    }
};

void test(vector<int64_t> nums1, vector<int64_t> nums2)
{
    TreeNode* root1 = makeTree(nums1);
    TreeNode* root2 = makeTree(nums2);
    Solution solution;
    TreeNode* newRoot = solution.mergeTrees(root1, root2);
    if(nullptr != newRoot)
    {
        cout << newRoot->val << endl;
        return;
    }
    return;
}

int main()
{
    test({1, 3, 2, 5}, {2, 1, 3, NIL, 4, NIL, 7});
    return 0;
}

