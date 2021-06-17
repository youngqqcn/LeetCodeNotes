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
//   同时每个节点的左节点小于当前节点, 有节点大于当前节点,
//   子树节点还要和根节点比较



// 二叉搜索树, 中序遍历是有序的,  这个方法很巧妙, 实现起来非常简洁

class Solution
{
private:
    vector<int> nums;

    // 中序遍历
    void traverse(TreeNode *node)
    {
        if(nullptr == node) return;

        traverse(node->left);
        nums.push_back(node->val);
        traverse(node->right);
    }
public:
    bool isValidBST(TreeNode *root)
    {
        nums.clear();
        traverse(root);
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] >= nums[i+1]) return false;
        }
        return true;
    }
};

#define NIL (INT64_MIN)
TreeNode *makeTree(vector<int64_t> nodes)
{
    if (nodes.empty())
    {
        return nullptr;
    }

    // 根据 nodes (前序遍历) 生成一棵树
    TreeNode *root = new TreeNode( int(nodes[0]));
    TreeNode *curNode = root;

    // [5,1,4,null,null,3,6]。      q [4]
    //     5
    //   /   \
    //  1      4
    // / \    /  \
    //n   n  3    6

    queue<TreeNode *> q;
    q.push(curNode);
    for (int i = 1; i < nodes.size(); )
    {
        curNode = q.front();
        q.pop();
        curNode->left = (nodes[i] == NIL) ? (nullptr) : new TreeNode(int(nodes[i]));
        if(i + 1 >= nodes.size()) break;
        curNode->right = (nodes[i + 1] == NIL) ? (nullptr) : new TreeNode(int(nodes[i + 1]));
        i += 2;

        if(nullptr != curNode->left ) {
            q.push(curNode->left);
        }
        if(nullptr != curNode->right) {
            q.push(curNode->right);
        }
    }
    return root;
}

void test(vector<long int> tree, bool expected)
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
    test({5, 1, 4, NIL , NIL, 3, 6, NIL, 4, 7, 8}, false);
    test({5,4,6,NIL,NIL,3,7}, false);
    test({2,1,3}, true);
    test({2,2,2}, false);
    test({2147483647,2147483647}, false);
    // cout << "hello world" << endl;
    return 0;
}
