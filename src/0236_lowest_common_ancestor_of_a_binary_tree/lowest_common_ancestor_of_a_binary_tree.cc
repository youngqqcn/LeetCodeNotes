// author: yqq
// date: 2021-07-26 18:20:04
// descriptions: https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
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
using namespace std;

#include "../include/make_tree.h"
using namespace std;


/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

示例 1：

       3
       / \
      5    1
     / \  / \
    6  2  0  8


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出：3
解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
示例 2：


输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出：5
解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
示例 3：

输入：root = [1,2], p = 1, q = 2
输出：1
 

提示：

树中节点数目在范围 [2, 105] 内。
-109 <= Node.val <= 109
所有 Node.val 互不相同 。
p != q
p 和 q 均存在于给定的二叉树中。


*/



// 和0235 一样的代码

class Solution {
public:
    unordered_map<TreeNode*,  vector<TreeNode *> >  m;
    vector<TreeNode *> path;
    bool qFlag = false, pFlag = false;
    void traverse(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(qFlag && pFlag) return;
        if(nullptr == root) return;

        path.push_back(root);
        if(root == p) {
            pFlag = true;
            m.insert(make_pair(p, path));
        }
        if(root == q) {
            qFlag = true;
            m.insert(make_pair(q, path));
        }

        if(nullptr != root->left) {
            traverse(root->left, p, q);
        }

        if(nullptr != root->right) {
            traverse(root->right, p, q);
        }
        path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        traverse(root, p, q);
        auto s1 = (*m.find(p)).second; // p 的祖先节点集合
        auto s2 = (*m.find(q)).second; // q 的祖先节点集合

        // 求两个集合的交集
        vector<TreeNode*> result(s1.size() + s2.size());
        auto last = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), result.begin());
        return *(last-1); // 最后一个元素
    }
};

void test(vector<int64_t> nums)
{

    {
        TreeNode* root = makeTree(nums);
        Solution sol;
        TreeNode *p = root->left, *q = root->right;
        TreeNode *expected = root;
        auto result =  sol.lowestCommonAncestor(root, p, q);
        if(result != expected)
        {
            cout << "FAILED" << endl;
            return;
        }
        cout << "PASSED" << endl;
    }

    {
        TreeNode* root = makeTree(nums);
        Solution sol;
        TreeNode *p = root->left, *q = root->left->right;
        TreeNode *expected = p;
        auto result =  sol.lowestCommonAncestor(root, p, q);
        if(result != expected)
        {
            cout << "FAILED" << endl;
            return;
        }
        cout << "PASSED" << endl;
    }

}
int main()
{
    test({6,2,8,0,4,7,9,NIL,NIL,3,5});
    return 0;
}

