// author: yqq
// date: 2021-07-26 17:26:03
// descriptions:
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

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

         6
       /   \
      2      8
    /  \    / \
   0    4  7   9
       / \
      3   5

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。


*/

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
    // test({6,2,8,0,4,7,9,NIL,NIL,3,5});
    return 0;
}

