// author: yqq
// date: 2021-08-05 14:44:12
// descriptions: https://leetcode-cn.com/problems/delete-node-in-a-bst
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
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7


*/


class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if(nullptr == root) return root;

        // 找到
        if (root->val == key)
        {
            if (nullptr == root->right) {
                return root->left;
            }
            else if (nullptr == root->left) {
                return root->right;
            }
            else
            {
                // 将root左子树,挂到root右子树最左的叶子节点的左侧
                TreeNode *qtmp = root->right;
                for (; qtmp != nullptr && qtmp->left != nullptr;)
                {
                    qtmp = qtmp->left;
                }
                qtmp->left = root->left;
                return root->right;
            }
        }

        if (key > root->val ) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val ) {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};


void inOrderTraverse(TreeNode* root,  vector<int> &nodes)
{
    if(nullptr == root) return;
    inOrderTraverse(root->left, nodes);
    nodes.push_back(root->val);
    inOrderTraverse(root->right, nodes);
}

void test(vector<int64_t> nums, int key)
{
    TreeNode* root = makeTree(nums);
    Solution sol;
    TreeNode* newRoot = sol.deleteNode(root, key);
    vector<int> nodes;
    inOrderTraverse(root, nodes);
    for(int i = 1; i < nodes.size(); i++)
    {
        if(nodes[i-1] > nodes[i]) {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({5,3,6,2,4,NIL,7}, 3);
    return 0;
}

