// author: yqq
// date: 2021-06-18 13:37:53
// descriptions:
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
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/


// 思路:

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int depth(TreeNode *node)
    {
        if(nullptr == node) return 0;
        return max(depth(node->left), depth(node->right)) + 1;
    }

public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};


void test(vector<long int> tree, int expected)
{
    TreeNode *root = makeTree<TreeNode>(tree);
    Solution sol;
    auto result = sol.maxDepth(root);

    if (result != expected)
    {
        cout << "FAILED" << "expected " << expected << " got" <<  result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({3,9,20,null,null,15,7}, 3);
    test({1,2}, 2);
    cout << "hello world" << endl;
    return 0;
}

