// author: yqq
// date: 2021-07-16 10:16:03
// descriptions: https://leetcode-cn.com/problems/house-robber-iii/
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
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，
每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

输出: 7
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

class Solution
{
public:

    int rob_v1(TreeNode *root)
    {
        // 递归终止
        if( nullptr == root) return 0;
        if(nullptr == root->left && nullptr == root->right) return root->val;

        // 偷父节点
        int n1 = root->val;
        if(nullptr != root->left) {
            n1 += rob(root->left->left) + rob(root->left->right);
        }
        if(nullptr != root->right) {
            n1 += rob(root->right->left) + rob(root->right->right);
        }

        // 不偷父节点
        int n2 = 0;
        if(nullptr != root) {
            n2 += rob(root->left) + rob(root->right);
        }

        return max(n1, n2);
    }

    // 记忆化
    unordered_map<TreeNode *, int> records;

    int rob(TreeNode *root)
    {
        // 递归终止
        if( nullptr == root) return 0;
        if(nullptr == root->left && nullptr == root->right) return root->val;
        // 如果有则返回
        if(records.find(root) != records.end()) return records[root];

        // 偷父节点
        int n1 = root->val;
        if(nullptr != root->left) {
            n1 += rob(root->left->left) + rob(root->left->right);
        }
        if(nullptr != root->right) {
            n1 += rob(root->right->left) + rob(root->right->right);
        }

        // 不偷父节点
        int n2 = 0;
        if(nullptr != root) {
            n2 += rob(root->left) + rob(root->right);
        }

        // 记录本次递归的结果, 将来可能用到
        int ret = max(n1, n2);
        records[root] = ret;
        return ret;
    }


    // 动态规划
    


};

int rob(struct TreeNode *root)
{
    return 0;
}

void test(vector<int64_t> nums, int expected)
{
    Solution sol;
    TreeNode *root = makeTree(nums);
    auto result = sol.rob(root);
    if (expected != result)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({3, 2, 3, NIL, 3, NIL, 1}, 7);
    test({3, 4, 5, 1, 3, null, 1}, 9);
    test({2, 1, 3, null, 4}, 7);
    test({4,2,null,3,1,null,null,5}, 12);
    return 0;
}
