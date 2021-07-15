// author: yqq
// date: 2021-07-15 09:46:14
// descriptions: https://leetcode-cn.com/problems/house-robber
#include <iostream>
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

/*

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

class Solution
{
public:
    int rob(vector<int> &a)
    {
        // dp数组定义:  dp[i] 表示 a[0..i-1] 的最大金额
        // 初始化: dp[0] = 0  dp[1] = a[0]
        // 状态转移方程: dp[i] = max(a[i - 1] + dp[i-2] ,  dp[i-1])
        // 遍历方向: 从左到右

        if(a.empty()) return 0;

        vector<int> dp(a.size() + 1);
        dp[0] = 0, dp[1] = a[0];

        for(int i = 2; i < dp.size(); i++)
        {
            dp[i] = max( a[i - 1] + dp[i - 2], dp[i-1]);
        }
        return dp[dp.size() - 1];
    }

    // TODO: 还可以优化空间, 用3变量代替dp数组,  做到 O(1)空间复杂度
};


#define MAX(a, b) ((a > b) ? (a) : (b))
int rob(int *a, int aSize)
{
    // 动态规划:
    //
    // dp数组定义:  dp[i] 表示 a[0..i-1] 的最大金额
    // 初始化: dp[0] = 0  dp[1] = a[0]
    // 状态转移方程: dp[i] = max(a[i - 1] + dp[i-2] ,  dp[i-1])
    // 遍历方向: 从左到右

    if(0 == aSize) return 0;
    int dpSize  = aSize +  1;
    int *dp = (int *)calloc(dpSize, sizeof(int));
    dp[0] = 0, dp[1] = a[0];
    for(int i = 2; i < dpSize; i++)
    {
        dp[i] = MAX(a[i - 1] + dp[i - 2] , dp[i-1]);
    }

    int result = dp[dpSize - 1];
    free(dp);
    dp = NULL;
    return result;
}

void test(vector<int> nums, int expected)
{
    // Solution sol;
    // auto result = sol.rob(nums);
    auto result = rob(nums.data(), nums.size());
    if (expected != result)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, 2, 3, 1}, 4);
    test({2, 7, 9, 3, 1}, 12);
    test({2, 1, 1, 2}, 4);
    test({2, 4, 8, 9, 9, 3}, 19);
    cout << "hello world" << endl;
    return 0;
}
