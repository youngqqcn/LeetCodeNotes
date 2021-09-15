// author: yqq
// date: 2021-09-15 15:02:35
// descriptions: https://leetcode-cn.com/problems/search-in-a-binary-search-tree
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
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。
返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2
     / \
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        if(nullptr == root) return nullptr;
        if(val < root->val ) return searchBST(root->left, val);
        if(val > root->val) return searchBST(root->right, val);
    }
};


void test(vector<int64_t> nums, int val)
{
    TreeNode* root = makeTree(nums);
    Solution sol;
    TreeNode *node = sol.searchBST(root, val);
}

int main()
{

    return 0;
}

