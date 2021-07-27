// author: yqq
// date: 2021-07-27 11:58:53
// descriptions: https://leetcode-cn.com/problems/binary-tree-paths
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

#include <sstream>

#include "../include/make_tree.h"
using namespace std;



/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void traverse(TreeNode* root)
    {
        path.push_back(root->val);
        if(nullptr == root->left && nullptr == root->right) {
            result.push_back(path);
            return;
        }

        if(nullptr != root->left) {
            traverse(root->left);
            path.pop_back();
        }

        if(nullptr != root->right) {
            traverse(root->right);
            path.pop_back();
        }
    }

    void formatResult(vector<string> &paths)
    {
        for(int i = 0; i < result.size(); i++) {
            string p;
            for(int j = 0; j < result[i].size(); j++){
                p += to_string(result[i][j]);
                if(j != result[i].size() - 1) {
                    p += "->";
                }
            }
            paths.push_back(p);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        if(nullptr == root) return {};

        traverse(root);
        vector<string> paths;
        formatResult(paths);
        return paths;
    }
};

void test(vector<int64_t> nums, set<string> expected)
{
    TreeNode *root = makeTree(nums);
    Solution sol;
    auto result = sol.binaryTreePaths(root);
    for(auto item : result)
    {
        auto it = expected.find(item);
        if(it == expected.end())
        {
            cout << "FAILED" << endl;
            return;
        }
        expected.erase(it);
    }

    if(!expected.empty())
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, 2, 3, NIL, 5}, {"1->2->5", "1->3"});
    return 0;
}

