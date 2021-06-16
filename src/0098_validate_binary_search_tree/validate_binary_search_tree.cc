// author: yqq
// date: 2021-06-16 17:24:10
// descriptions:
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
using namespace std;

/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

示例 1:

输入:
    2
   / \
  1   3
输出: true


示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

*/

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 思路:
//   在左子树中找比当前节点大的, 在右子树中找比当前节点小的, 如果找到则不是二叉搜索树, 否则是的

class Solution
{
private:
    bool flag = true;
    void recursive(TreeNode *cur, int minNum, int maxNum)
    {
        if(nullptr == cur) {
            return;
        }

        if(minNum < cur->val && cur->val < maxNum) {
            recursive(cur->left, minNum, cur->val);
            if(!flag) return;
            recursive(cur->right, cur->val,  maxNum);
        }else{
            flag = false;
        }
        return;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        recursive(root, root->val - 1, root->val + 1 );
        return flag;
    }
};

#define NIL (INT32_MIN)
TreeNode *makeTree(vector<int> nodes)
{
    if (nodes.empty())
    {
        return nullptr;
    }

    // 根据 nodes (前序遍历) 生成一棵树
    TreeNode *root = new TreeNode(nodes[0]);
    TreeNode *curNode = root;

    // [5,1,4,null,null,3,6]。      q [4]
    //     5
    //   /   \
    //  1      4
    // / \    /  \
    //n   n  3    6

    queue<TreeNode *> q;
    q.push(curNode);
     for (int i = 1; i < nodes.size() - 1; i += 2)
    {
        curNode = q.front();
        q.pop();
        curNode->left = (nodes[i] == NIL) ? (nullptr) : new TreeNode(nodes[i]);
        curNode->right = (nodes[i + 1] == NIL) ? (nullptr) : new TreeNode(nodes[i + 1]);

        if(nullptr != curNode->left ) {
            q.push(curNode->left);
        }
        if(nullptr != curNode->right) {
            q.push(curNode->right);
        }
    }
    return root;
}

void test(vector<int> tree, bool expected)
{
    TreeNode *root = makeTree(tree);
    Solution sol;
    bool result = sol.isValidBST(root);
    if (expected != result)
    {
        cout << "FAILED" << " expected " << expected << " got " << result  <<  endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    // test({5, 1, 4, NIL, NIL, 3, 6, NIL, 4, 7, 8}, false);
    test({5,4,6,NIL,NIL,3,7}, false);
    // test({2,1,3}, true);
    // test({2,2,2}, false);
    cout << "hello world" << endl;
    return 0;
}
