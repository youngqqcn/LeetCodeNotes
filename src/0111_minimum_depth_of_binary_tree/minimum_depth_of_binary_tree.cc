// author: yqq
// date: 2021-06-18 17:49:02
// descriptions: https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>


#include "../include/make_tree.h"
using namespace std;

/*

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

示例 1：

            3
           / \
          9   20
              / \
             15  7

输入：root = [3,9,20,null,null,15,7]
输出：2


示例 2：

       2
        \
         3
          \
           4
            \
             5
              \
               6

输入：root = [2,null,3,null,4,null,5,null,6]
输出：5

提示：
树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
*/


// 注意: null 不能作为叶子节点

class Solution {
    bool isLeafNode(TreeNode *node)
    {
        return  (nullptr == node->left)  && (nullptr == node->right);
    }
    int mindepth(TreeNode *root)
    {
        if(nullptr == root) return  INT32_MAX;
        if(isLeafNode(root)) return 1;
        return min(mindepth(root->left), mindepth(root->right)) + 1;
    }

    // TODO: 使用迭代法

public:
    int minDepth(TreeNode* root) {
        if(nullptr == root) return 0;
        return mindepth(root);
    }
};


void test(vector<long int> nums , int expected)
{
    TreeNode* tree = makeTree(nums);
    Solution solution;
    auto result = solution.minDepth(tree);
    if(result != expected) {
        cout << "FAILED" << endl;
    }else {
        cout << "PASSED" << endl;
    }
}


int main()
{
    test({3,9,20,null,null,15,7}, 2);
    test({2,null,3,null,4,null,5,null,6}, 5);
    test({}, 0);
    cout << "hello world" << endl;
    return 0;
}

