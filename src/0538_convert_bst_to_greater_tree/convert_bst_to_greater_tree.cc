// author: yqq
// date: 2021-08-25 15:04:43
// descriptions: https://leetcode-cn.com/problems/convert-bst-to-greater-tree
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
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

示例 1：
输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

示例 2：
输入：root = [0,null,1]
输出：[1,null,1]

示例 3：
输入：root = [1,0,2]
输出：[3,3,2]

示例 4：
输入：root = [3,2,4,1]
输出：[7,9,4,10]
 

提示：

树中的节点数介于 0 和 10^4 之间。
每个节点的值介于 -10^4 和 10^4 之间。
树中的所有值 互不相同 。
给定的树为二叉搜索树。

*/

class Solution
{
private:
    int sum;
    void traverse(TreeNode* root)
    {
        if(nullptr == root){
            return;
        }

        traverse(root->right);

        sum += root->val;
        root->val = sum;

        traverse(root->left);
        return;
    }

public:
    TreeNode* convertBST(TreeNode* root)
    {
        sum = 0;
        traverse(root);
        return root;
    }
};

void test(vector<int64_t> nums, vector<int64_t> expected)
{
    TreeNode *root = makeTree(nums);
    Solution sol;
    TreeNode *newRoot= sol.convertBST(root);
    if(newRoot)
    {
        cout << newRoot->val << endl;
    }
}

int main()
{

    test({1,0,2}, {3,3,2});
    test({3,2,4,1}, {7,9,4,10});
    test({0,NIL,1}, {1,NIL,1});
    test({4,1,6,0,2,5,7,null,null,null,3,null,null,null,8}, {30,36,21,36,35,26,15,null,null,null,33,null,null,null,8});

    return 0;
}

