// author: yqq
// date: 2021-08-27 14:17:57
// descriptions: https://leetcode-cn.com/problems/trim-a-binary-search-tree
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
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。
通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
修剪树不应该改变保留在树中的元素的相对结构（即，如果没有被移除，原有的父代子代关系都应当保留）。

可以证明，存在唯一的答案。

所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

 

示例 1：

    1               1
   / \     ==>       \
  0   2               2


输入：root = [1,0,2], low = 1, high = 2
输出：[1,null,2]

示例 2：

      3                     3
     / \                   /
    0   4                 2
     \          ==>      /
      2                 1
     /
    1

输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
输出：[3,2,null,1]

示例 3：

输入：root = [1], low = 1, high = 2
输出：[1]


示例 4：

输入：root = [1,null,2], low = 1, high = 3
输出：[1,null,2]


示例 5：

输入：root = [1,null,2], low = 2, high = 4
输出：[2]
 

提示：

树中节点数在范围 [1, 10^4] 内
0 <= Node.val <= 10^4
树中每个节点的值都是唯一的
题目数据保证输入是一棵有效的二叉搜索树
0 <= low <= high <= 10^4
*/



class Solution
{
private:
    TreeNode* trim(TreeNode* root, int low, int high)
    {
        if(nullptr == root) return nullptr;

        // 因为是二叉搜索树，每个节点的值不同， 左节点一定小于根节点，右节点一定大于根节点
        // 如果连根节点都不在范围内，
        //   如果根节点大于范围， 那么，根节点和右子树都要被裁剪掉
        //   如果根节点小于范围， 那么，根节点和左子树都要被裁剪掉
        if(root->val < low) {
            return trim(root->right, low, high);
        }

        if(root->val > high) {
            return trim(root->left, low, high);
        }

        root->left = trim(root->left, low, high);
        root->right = trim(root->right, low, high);
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high)
    {
        return trim(root, low, high);
    }
};

void test(vector<int64_t> nums, int low, int high)
{
    TreeNode* root = makeTree(nums);
    Solution sol;
    TreeNode* newRoot = sol.trimBST(root, low, high);
    if(nullptr != newRoot)
    {
        cout << newRoot->val << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    /*
            3
           / \
          2   4
         /
        1
    */
    test({3,2,4,1}, 1, 1); // [1]


    test({1,null,2}, 2, 4); // expected {2}

    /*
        3
       / \
      1   4    ==>       3
       \                  \
        2                  4
    */
    test({3,1,4,null,2}, 3, 4); // expected {3, null, 4}


    test({3,0,4,null,2,null,null,1}, 1, 3);
    test({1}, 1, 2);
    test({1, null, 2}, 1, 3);
    test({1, null, 2}, 2, 4);

    return 0;
}

