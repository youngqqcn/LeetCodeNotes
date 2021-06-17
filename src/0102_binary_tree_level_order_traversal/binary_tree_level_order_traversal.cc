// author: yqq
// date: 2021-06-17 18:03:13
// descriptions: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>

#include "make_tree.h"
#include <queue>
using namespace std;

/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层序遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    vector<vector<int>> result;
    void levelTraverse(TreeNode *node)
    {
        queue<TreeNode*> curLevel;
        queue<TreeNode*> nextLevel;
        curLevel.push(node);
        for(;!curLevel.empty();)
        {
            vector<int> nums;
            for(;!curLevel.empty();)
            {
                TreeNode *p = curLevel.front(); curLevel.pop();
                if(nullptr != p){
                    nums.push_back(p->val);
                    nextLevel.push(p->left);
                    nextLevel.push(p->right);
                }
            }
            if(!nums.empty()){
                result.push_back(nums);
            }
            curLevel.swap(nextLevel);
        }
    }

    // BFS  广度优先搜索 实现
    void BFS(TreeNode *node)
    {
        if(nullptr == node) return;
        queue<TreeNode *> q;
        q.push(node);
        while(!q.empty())
        {
            int curNodeLevelCount = q.size(); // 记录当前层的节点个数
            vector<int> vctCur;
            for(int i  = 0; i < curNodeLevelCount; i++) { // 一次性处理当前层
                TreeNode *cur = q.front(); q.pop();
                vctCur.push_back(cur->val);
                if(nullptr != cur->left ) {
                    q.push(cur->left);
                }
                if(nullptr != cur->right) {
                    q.push(cur->right);
                }
            }
            if(!vctCur.empty()) {
                result.push_back(std::move(vctCur));
            }
        }
    }

public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // levelTraverse(root);
        BFS(root);
        return result;
    }
};

void test(vector<long int> tree, vector<vector<int>> expected)
{
    TreeNode *root = makeTree<TreeNode>(tree);
    Solution sol;
    auto result = sol.levelOrder(root);

    if (result.size() != expected.size())
    {
        cout << "FAILED" << endl;
        return;
    }
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i] != expected[i])
        {
            cout << "FAILED" << endl;
            return;
        }
    }

    cout << "PASSED" << endl;
}

int main()
{
    test({3,9,20,NIL,NIL,15,7}, {{3}, {9, 20}, {15, 7}});
    test({}, {} );
    // cout << "hello world" << endl;
    return 0;
}
