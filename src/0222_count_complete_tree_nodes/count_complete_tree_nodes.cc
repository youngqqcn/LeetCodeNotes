// author: yqq
// date: 2021-07-26 15:33:00
// descriptions: https://leetcode-cn.com/problems/count-complete-tree-nodes
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
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例1:

       1
     /   \
    2     3
   / \    /
  4   5  6


输入：root = [1,2,3,4,5,6]
输出：6

示例 2：
输入：root = []
输出：0

示例 3：
输入：root = [1]
输出：1


提示：

树中节点的数目范围是[0, 5 * 10^4]
0 <= Node.val <= 5 * 10^4
题目数据保证输入的树是 完全二叉树

*/



class Solution {
public:
    int countNodes(TreeNode* root)
    {
        if(nullptr == root) return 0;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};


void test(vector<int64_t> nums, int expected)
{
    Solution sol;
    TreeNode *root = makeTree(nums);
    auto result = sol.countNodes(root);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,3,4,5,6}, 6);
    test({}, 0);
    test({1}, 1);
    return 0;
}

