#pragma once

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define NIL (INT64_MIN)
#define null NIL

/*

输入 [5,1,4,NIL,NIL,3,6]。      q [4]

构造一棵树:
         5
       /    \
      1      4
     / \    /  \
    n   n  3    6

其中 n表示 nullptr
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



template <typename Tree=TreeNode>
Tree *makeTree(vector<int64_t> nodes)
{
    if (nodes.empty())
    {
        return nullptr;
    }

    // 根据 nodes (前序遍历) 生成一棵树
    Tree *root = new Tree(int(nodes[0]));
    Tree *curNode = root;

    queue<Tree *> q;
    q.push(curNode);
    for (int i = 1; i < nodes.size();)
    {
        curNode = q.front();
        q.pop();
        curNode->left = (nodes[i] == NIL) ? (nullptr) : new Tree(int(nodes[i]));
        if (i + 1 >= nodes.size())
            break;
        curNode->right = (nodes[i + 1] == NIL) ? (nullptr) : new Tree(int(nodes[i + 1]));
        i += 2;

        if (nullptr != curNode->left)
        {
            q.push(curNode->left);
        }
        if (nullptr != curNode->right)
        {
            q.push(curNode->right);
        }
    }
    return root;
}


