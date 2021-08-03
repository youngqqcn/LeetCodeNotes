// author: yqq
// date: 2021-08-03 13:45:20
// descriptions: https://leetcode-cn.com/problems/sum-of-left-leaves
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
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

*/

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        if(root == nullptr) {
            return 0;
        }

        if(nullptr != root->left && nullptr == root->left->left && nullptr == root->left->right) {
            sum += root->left->val;
        }

        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
};

void test(vector<int64_t> nums, int expected)
{
    TreeNode* root = makeTree(nums);
    Solution sol;
    auto result = sol.sumOfLeftLeaves(root);
    if( expected != result)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({3, 9, 20, NIL, NIL, 15, 7}, 24);

    return 0;
}

