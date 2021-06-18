// author: yqq
// date: 2021-06-18 13:55:08
// descriptions: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>

#include "make_tree.h"
using namespace std;


/*

根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

// 思路:
//   1. 后序遍历的最后一个元素就是整棵树的根节点
//   2. 得知根节点之后, 假设根节点为r, 根据中序遍历, 在中序遍历序列中r左边的,即[0:r] 就是左子树的元素, r右边的,即[r : size-1]就是右子树的元素
//   3. 对序列第2步中的[0:r] , [r:size]重复 第1, 2步操作, 直到[0:r] 和 [r:size]为空

class Solution {
private:
#if 0
    // 这种方式比较简洁, 但是, 右很多数据拷贝
    TreeNode* build(vector<int> inorder, vector<int> postorder)
    {
        // 递归终止
        if(inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        // 1. 从postOrder中找出最后一个元素作为根节点
        int rootNumber = postorder.back();
        TreeNode* root = new TreeNode(rootNumber);

        // 2. 根据 rootNumber 将inorder一分为二, rootNumber左边的序列是左子树的元素, rootNumber右边的序列是右子树的元素
        auto r = std::find(inorder.begin(), inorder.end(),rootNumber);
        vector<int> leftInorder(inorder.begin(), r);
        vector<int> rightInorder(r+1, inorder.end());

        vector<int> leftPostorder;
        vector<int> rightPostorder;
        for(int i = 0; i < postorder.size(); i++)
        {
            if(leftInorder.end() != std::find(leftInorder.begin(), leftInorder.end(), postorder[i])){
                leftPostorder.push_back(postorder[i]);
            }
            else if(rightInorder.end() != std::find(rightInorder.begin(), rightInorder.end(), postorder[i])){
                rightPostorder.push_back(postorder[i]);
            }
        }

        // 3.递归
        root->left = build(leftInorder, leftPostorder);
        root->right = build(rightInorder, rightPostorder);
        return root;
    }
#endif

    TreeNode* build(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        // 递归终止
        if(inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        if(inEnd - inStart == 0 && postEnd - postStart == 0 ) {
            return new TreeNode(inorder[inEnd]);
        }

        // 1. 从postOrder中找出最后一个元素作为根节点
        int rootNumber = postorder[postEnd];
        TreeNode* root = new TreeNode(rootNumber);

        // 2. 根据 rootNumber 将inorder一分为二, rootNumber左边的序列是左子树的元素, rootNumber右边的序列是右子树的元素
        // 在 inorder中找出 rootNumber 的下标rootIndex,
        // 然后, inorder[0: rootInex] 就是左子树的, inorder[rootInex: size] 就是右子树的
        // 然后, postorder[0 : rootInex) 就是左子树的, postorder[rootInex: size - 1] 就是右子树的,
        int rootIndex = 0;
        for(; rootIndex < inEnd - inStart + 1 && rootNumber != inorder[inStart + rootIndex];  rootIndex++) {
        }

        // 3.递归, 为了避免数据拷贝导致 leetcode执行超时, 需要计算左右的索引
        int leftInStart = inStart;  int leftPostStart = postStart;
        int leftInEnd = inStart + rootIndex-1; int leftPostEnd = postStart+rootIndex-1;
        int rightInStart = inStart+rootIndex+1 ; int rightPostStart = postStart+rootIndex;
        int rightInEnd = inEnd;  int rightPostEnd = postEnd - 1 ;
        root->left = build(inorder, leftInStart, leftInEnd, postorder, leftPostStart, leftPostEnd);
        root->right = build(inorder, rightInStart, rightInEnd,  postorder, rightPostStart, rightPostEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // vector<int> in(inorder.begin(), inorder.end());
        // vector<int> post(postorder.begin(), postorder.end());
        // return build(in, post);
        return build(inorder, 0, inorder.size() - 1 , postorder, 0, postorder.size() - 1);
    }
};



void test(vector<int> inorder, vector<int> postorder)
{
    Solution sol;
    TreeNode *root= sol.buildTree(inorder, postorder);
    if(root == nullptr){
        cout << "FAILED" << endl;
    }
}

int main()
{
    // test({9,3,15,20,7}, {9,15,7,20,3});
    test({2,1},{2,1});
    cout << "hello world" << endl;
    return 0;
}

