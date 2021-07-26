// author: yqq
// date: 2021-07-26 16:15:55
// descriptions: https://leetcode-cn.com/problems/invert-binary-tree/
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
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
*/

class Solution
{
public:
    // TreeNode* invertTree(TreeNode* root)
    // {
    //     if(nullptr == root) return root;

    //     TreeNode *pLeft = root->left;
    //     TreeNode *pRight = root->right;
    //     root->left = invertTree(pRight);
    //     root->right = invertTree(pLeft);
    //     return root;
    // }

    TreeNode* invertTree(TreeNode* root)
    {
        if(nullptr == root) return root;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};


void test(vector<int64_t> nums)
{
    TreeNode *root = makeTree(nums);
    Solution sol;
    TreeNode* newRoot= sol.invertTree(root);
}

int main()
{
    test({4, 2, 7, 1, 3, 6, 9});
    return 0;
}

