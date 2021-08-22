// author: yqq
// date: 2021-08-22 15:05:39
// descriptions: https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
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
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

*/


class Solution
{
private:
    void traverse(TreeNode *root, unordered_map<int, int> &nmap)
    {
        if(nullptr == root) return;

        nmap[root->val] += 1;
        traverse(root->left, nmap);
        traverse(root->right, nmap);
    }
public:
    vector<int> findMode(TreeNode* root)
    {
        unordered_map<int, int> nmap;
        traverse(root, nmap);

        vector<int> result;
        int max = max_element(nmap.begin(), nmap.end(), [](pair<int, int> a, pair<int, int> b){
            return a.second < b.second;
        })->second;

        for_each(nmap.begin(), nmap.end(), [max, &result](pair<int, int> a){
            if(a.second == max) {
                result.push_back(a.first);
            }
        });
        return result;
    }
};

void test(vector<int64_t> nums, vector<int> expected)
{
    TreeNode *root = makeTree(nums);
    Solution sol;
    auto result = sol.findMode(root);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, NIL, 2, 2}, {2});
    return 0;
}

