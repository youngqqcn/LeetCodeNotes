// author: yqq
// date: 2021-06-18 17:11:08
// descriptions: https://leetcode-cn.com/problems/balanced-binary-tree/
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
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1:

     3
    /  \
   9    20
       /  \
     15    7

输入：root = [3,9,20,null,null,15,7]
输出：true


示例 2:

         1
        /  \
       2    2
      / \
     3   3
    / \
   4   4

输入：root = [1,2,2,3,3,null,null,4,4]
输出：false


示例 3：
输入：root = []
输出：true

树中的节点数在范围 [0, 5000] 内
-10^4 <= Node.val <= 10^4
*/


// 思路
//   1. 递归
//   2. 迭代

class Solution {
private:
    int height(TreeNode *node)
    {
        if(nullptr == node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
public:

    bool isBalanced(TreeNode* root) {
        if(nullptr == root) return true;
        if(abs(height(root->left) - height(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    // TODO: 迭代实现
};


void test(vector<long int> nums , bool expected)
{
    TreeNode* tree = makeTree(nums);
    Solution solution;
    bool result = solution.isBalanced(tree);
    if(result != expected) {
        cout << "FAILED" << endl;
    }else {
        cout << "PASSED" << endl;
    }
}


int main()
{
    test({3,9,20,null,null,15,7}, true);
    test({1,2,2,3,3,null,null,4,4}, false);
    test({}, true);
    cout << "hello world" << endl;
    return 0;
}

