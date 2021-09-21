// author: yqq
// date: 2021-09-20 16:13:53
// descriptions: https://leetcode-cn.com/problems/binary-tree-cameras
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
给定一个二叉树，我们在树的节点上安装摄像头。

节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。

计算监控树的所有节点所需的最小摄像头数量。

 
[o] : 表示摄像头

示例 1：

       ( )
       /
     ([o])
    /     \
  ( )     ( )


输入：[0,0,null,0,0]
输出：1
解释：如图所示，一台摄像头足以监控所有节点。


示例 2：
         ( )
         /
      ([o])
      /
    ( )
    /
  ([o])
    \
    ( )


输入：[0,0,null,0,null,0,null,null,0]
输出：2
解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。

提示：

给定树的节点数的范围是 [1, 1000]。
每个节点的值都是 0。

*/


class Solution {
private:
    enum State {
        NOCOVER,    // 无覆盖
        CAMERA,     // 有摄像头
        COVER,      // 有覆盖
    };

    int result;
    int traverse(TreeNode *root)
    {
        // 递归终止条件
        if(nullptr == root) {
            return State::COVER; // 空节点当作有覆盖
        }

        int left = traverse(root->left);
        int right = traverse(root->right);
        if(left == State::COVER && right == State::COVER) {
            return State::NOCOVER;
        }

        // 如果左右存在 无覆盖 的, 当前节点必须放置摄像头
        if(left == State::NOCOVER || right == State::NOCOVER) {
            result++;
            return State::CAMERA;
        }

        if(left == State::CAMERA || right == State::CAMERA) {
            return State::COVER;
        }
        return -1;
    }
public:
    int minCameraCover(TreeNode* root)
    {
        result = 0;
        if(State::NOCOVER == traverse(root)) {
            result++;
        }
        return result;
    }
};

void test(vector<int64_t> num, int expected)
{
    TreeNode* root = makeTree(num);

    Solution sol;
    int result = sol.minCameraCover(root);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
    freeTree(root); // 释放内存
}

int main()
{
    test({0,0,null,0,0}, 1);
    test({0,0,null,0,null,0,null,null,0}, 2);
    return 0;
}

