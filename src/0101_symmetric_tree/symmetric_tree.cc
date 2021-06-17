// author: yqq
// date: 2021-06-17 14:51:35
// descriptions: https://leetcode-cn.com/problems/symmetric-tree/
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
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

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

// 思路:
//    对左子树进行中序遍历(左,根,右), 右子树进行 反中序遍历(右,根,左) ,
//    对左子树进行前序遍历(根,左,右), 右子树进行 反后序遍历(根,右,左) ,
//    对左子树进行后序遍历(左,右,根), 右子树进行 反后序遍历(右,左,根) ,
class Solution
{
private:

    // 忽略内存泄漏
    void fixNullNode(TreeNode *node)
    {
        if(node == nullptr) return;

        if(!(node->left == nullptr && node->right == nullptr)) {
            if(node->left == nullptr) {
                node->left = new TreeNode(INT32_MIN);
            }
            else if(node->right == nullptr) {
                node->right = new TreeNode(INT32_MIN);
            }
        }
        fixNullNode(node->left);
        fixNullNode(node->right);
    }

    void traverse_mid(TreeNode *node, vector<int>& nums)
    {
        if (nullptr == node){
            return;
        }

        traverse_mid(node->left, nums);
        nums.push_back(node->val);
        traverse_mid(node->right, nums);
    }

    void traverse_rmid(TreeNode *node, vector<int>& nums)
    {
        if (nullptr == node){
            return;
        }

        traverse_rmid(node->right, nums);
        nums.push_back(node->val);
        traverse_rmid(node->left, nums);
    }

    void traverse_rprev(TreeNode *node, vector<int>& nums)
    {
        if (nullptr == node){
            return;
        }
        nums.push_back(node->val);
        traverse_rprev(node->right, nums);
        traverse_rprev(node->left, nums);
    }

    void traverse_prev(TreeNode *node, vector<int>& nums)
    {
        if (nullptr == node){
            return;
        }

        nums.push_back(node->val);
        traverse_prev(node->left, nums);
        traverse_prev(node->right, nums);
    }

    void traverse_post(TreeNode *node, vector<int>& nums)
    {
         if (nullptr == node){
            return;
        }

        traverse_post(node->left, nums);
        traverse_post(node->right, nums);
        nums.push_back(node->val);
    }

    void traverse_rpost(TreeNode *node, vector<int>& nums)
    {
         if (nullptr == node){
            return;
        }

        traverse_rpost(node->right, nums);
        traverse_rpost(node->left, nums);
        nums.push_back(node->val);
    }


    // 两个指针, p, q,  p向左时, q向右; p向右时, q向左
    bool check(TreeNode *p, TreeNode *q)
    {
        if(nullptr == p && nullptr == q) return true;
        if(nullptr == p || nullptr == q ) return false;
        if(p->val != q->val) return false;
        return check(p->left, q->right) && check(p->right, q->left);
    }


public:
    bool isSymmetric_v1(TreeNode *root)
    {
        fixNullNode(root);
        vector<int> nums1;
        vector<int> nums2;
        traverse_mid(root->left, nums1);
        traverse_rmid(root->right, nums2);
        if(nums1 != nums2) {
            return false;
        }

        nums1.clear();
        nums2.clear();
        traverse_prev(root->left, nums1);
        traverse_rprev(root->right, nums2);
        if(nums1 != nums2)
        {
            return false;
        }

        nums1.clear();
        nums2.clear();
        traverse_post(root->left, nums1);
        traverse_rpost(root->right, nums2);
        if(nums1 != nums2)
        {
            return false;
        }


        return true;
    }


    // 递归
    bool isSymmetric_v2(TreeNode *root)
    {
        return check(root->left, root->right);
    }


    // 迭代
    bool isSymmetric(TreeNode *root)
    {
        queue<TreeNode*> nodesQueue;

        TreeNode *p;
        TreeNode *q;
        nodesQueue.push(root->left);
        nodesQueue.push(root->right);
        for(;!nodesQueue.empty();)
        {
            p = nodesQueue.front();
            nodesQueue.pop();
            q = nodesQueue.front();
            nodesQueue.pop();

            if(nullptr == p && nullptr == q) continue;
            if(nullptr == p || nullptr == q ) return false;
            if(p->val != q->val) return false;

            nodesQueue.push(p->left);
            nodesQueue.push(q->right);

            nodesQueue.push(p->right);
            nodesQueue.push(q->left);
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
    TreeNode *root = new TreeNode(int(nodes[0]));
    TreeNode *curNode = root;

    // [5,1,4,null,null,3,6]。      q [4]
    //     5
    //   /   \
    //  1      4
    // / \    /  \
    //n   n  3    6

    queue<TreeNode *> q;
    q.push(curNode);
    for (int i = 1; i < nodes.size();)
    {
        curNode = q.front();
        q.pop();
        curNode->left = (nodes[i] == NIL) ? (nullptr) : new TreeNode(int(nodes[i]));
        if (i + 1 >= nodes.size())
            break;
        curNode->right = (nodes[i + 1] == NIL) ? (nullptr) : new TreeNode(int(nodes[i + 1]));
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

void test(vector<long int> tree, bool expected)
{
    TreeNode *root = makeTree(tree);
    Solution sol;
    bool result = sol.isSymmetric(root);
    if (expected != result)
    {
        cout << "FAILED"
             << " expected " << expected << " got " << result << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({1, 2, 2, 3, 4, 4, 3}, true);
    test({1, 2, 2, NIL, 3, NIL, 3}, false);
    test({1, 2, 2, 2, NIL, 2}, false);
    test({5,4,1,NIL,1,NIL,4,2,NIL,2,NIL}, false);
    test({2,3,3,4,5,5,4,NIL,NIL,8,9,9,8}, true);
    test({9,-42,-42,NIL,76,76,NIL,NIL,13,NIL,13}, false);
    return 0;
}
