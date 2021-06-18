// author: yqq
// date: 2021-06-18 18:33:51
// descriptions: https://leetcode-cn.com/problems/path-sum
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
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。

叶子节点 是指没有子节点的节点。
 

示例 1：
                    5
                  /   \
                 4     8
                /     /  \
              11     13   4
             /  \          \
            7    2          1


输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
输出：true


示例 2：
          1
         / \
        2   3

输入：root = [1,2,3], targetSum = 5
输出：false


示例 3：

    1
   /
  2

输入：root = [1,2], targetSum = 0
输出：false
 

提示：

树中节点的数目在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
*/




class Solution {
    bool isLeafNode(TreeNode *node)
    {
        return (nullptr == node->left) && ( nullptr == node->right);
    }

    bool pathSum_v1(TreeNode *node, int sum, int targetSum)
    {
        if(nullptr == node) return false;
        if(((sum +  node->val) == targetSum) && isLeafNode(node) ) {
            return true;
        }

        return pathSum(node->left, sum + node->val, targetSum) || pathSum(node->right, sum + node->val, targetSum);
    }

    // TODO: 迭代法, 类似层序遍历
    // FIXME: ========================
    bool pathSum(TreeNode *node, int sum, int targetSum)
    {
        queue<TreeNode*> q;
        q.push(node);
        int sum1 = 0, sum2 = 0;
        for(; !q.empty(); )
        {
            int curLevelSize = q.size();
            for(int i = 0; i < curLevelSize; i++)
            {
                TreeNode *cur  = q.front(); q.pop();
                if(sum + cur->val == targetSum && isLeafNode(cur)) return true;
                if( nullptr != cur->left) q.push(cur->left);
                if( nullptr != cur->right) q.push(cur->right);
            }
        }
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return  pathSum(root, 0, targetSum);
    }
};

void test(vector<long int> nums, int targetSum , bool expected)
{
    TreeNode* tree = makeTree(nums);
    Solution solution;
    auto result = solution.hasPathSum(tree, targetSum);
    if(result != expected) {
        cout << "FAILED" << endl;
    }else {
        cout << "PASSED" << endl;
    }
}


int main()
{
    test({5,4,8,11,null,13,4,7,2,null,null,null,1}, 22, true);
    test({1,2,3}, 5, false);
    test({1,2}, 0, false);

    cout << "hello world" << endl;
    return 0;
}

