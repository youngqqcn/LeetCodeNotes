// author: yqq
// date: 2021-08-23 16:05:04
// descriptions: https://leetcode-cn.com/problems/find-bottom-left-tree-value
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
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

示例 1:
      2
    /   \
   1     3

输入: root = [2,1,3]
输出: 1

示例 2:
        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
 

提示:

二叉树的节点个数的范围是 [1,10^4]
-2^31 <= Node.val <= 2^31 - 1 

*/


class Solution {
private:
    int maxDepth;
    int result;
    void traverse(TreeNode* root, int depth)
    {
        if(nullptr == root) return;

        traverse(root->left, depth + 1);
        traverse(root->right, depth + 1);
        if(maxDepth < depth) {
            maxDepth = depth;
            result = root->val;
        }
    }

public:
    // 1.层序遍历
    int findBottomLeftValue_v2(TreeNode* root)
    {
        vector<int> result;

        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty())
        {
            int curLevelNodes = q.size();

            if(!result.empty() && curLevelNodes > 0) {
                result.clear();
            }

            for(int i = 0; i < curLevelNodes; i++)
            {
                TreeNode *node = q.front(); q.pop_front();
                result.push_back(node->val);

                if(nullptr != node->left) {
                    q.push_back(node->left);
                }
                if(nullptr != node->right) {
                    q.push_back(node->right);
                }
            }
        }

        return result[0];
    }


    // 2.递归
    int findBottomLeftValue(TreeNode* root)
    {
        maxDepth = 0;
        result = root->val;
        traverse(root, 0);
        return result;
    }

};


void test(vector<int64_t> nums, int expected)
{
    TreeNode* root = makeTree(nums);
    Solution sol;
    auto result = sol.findBottomLeftValue(root);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({2, 1, 3}, 1);
    test({1, 2, 3, 4, NIL, 5, 6, NIL, NIL, 7}, 7);
    return 0;
}

