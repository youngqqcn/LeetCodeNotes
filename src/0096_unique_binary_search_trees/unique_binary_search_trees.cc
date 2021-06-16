// author: yqq
// date: 2021-06-16 15:25:52
// descriptions:https://leetcode-cn.com/problems/unique-binary-search-trees/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;


/*
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

示例 1：
输入：n = 3
输出：5

5种情况如下:
   1         1            2          3         3
     \        \          / \        /         /
      3        2        1   3      2        1
     /          \                 /           \
   2             3               1             2


示例 2：
输入：n = 1
输出：1
 

提示：
1 <= n <= 19
*/


// 官方的题解很值得学习, 结合leetcode-master的题解一起看, 对理解本题很有帮助
//   https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/

class Solution {
public:

    // 动态规划
    //
    // 非常重要一点: 组成不同二叉搜索的种数,只与元素个数有关, 与元素内容无关
    // dp数组定义: dp[i] 表示i个元素能够组成不同二叉搜索数的个数
    // 递推公式:  dp[i] += dp[j - 1] * dp[i - j] ;  其中 j的取值区间为[1, i] ,  包含i(即右子树元素个数为0, 左子树个数为i)
    //            以 i为根节点, dp[j - 1] 表示以j-1个数作为左子树的可能情况, dp[i-j] 表示i-j个数作为右子树的可能情况
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];  // 为什么是乘法呢? 即笛卡尔积
            }
        }
        return dp[n];
    }
};

void test(int n, int expected)
{
    Solution sol;
    int result = sol.numTrees(n);
    if(result != expected)
    {
        cout << "FAILED, expected " << expected << " got " << result <<endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test(3, 5);
    test(1, 1);
    test(0, 1);
    cout << "hello world" << endl;
    return 0;
}

