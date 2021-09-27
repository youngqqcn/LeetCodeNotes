// author: yqq
// date: 2021-09-27 16:46:12
// descriptions: https://leetcode-cn.com/problems/uncrossed-lines
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


/*
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。

现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：

nums1[i] == nums2[j]
且绘制的直线不与任何其他连线（非水平线）相交。

请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。


示例 1：

1   4   2
|     \
1   2   4

输入：nums1 = [1,4,2], nums2 = [1,2,4]
输出：2
解释：可以画出两条不交叉的线，如上图所示。
但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4
的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。


示例 2：

输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
输出：3


示例 3：

输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
输出：2
 

提示：

1 <= nums1.length <= 500
1 <= nums2.length <= 500
1 <= nums1[i], nums2[i] <= 2000
*/



class Solution {
private:
    int result;

    // 回溯法
    void backtracking(const vector<int>&nums1, int n1,  const vector<int>& nums2, int n2, int count)
    {
        for(int i = n1; i < nums1.size(); i++)
        {
            for(int j = n2; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    result = max(result, ++count);

                    // 回溯
                    backtracking(nums1, i+1, nums2, n2, count - 1);

                    n2 = j+1;
                    break;
                }
            }
        }
    }

public:

    // int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    // {
    //     result = 0;
    //     backtracking(nums1, 0, nums2, 0, 0);

    //     return result;
    // }

    // 最长公共子序列(LCS)
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
};


void test(vector<int> nums1, vector<int> nums2, int expected)
{
    Solution sol;
    auto result = sol.maxUncrossedLines(nums1, nums2);
    if(result != expected)
    {
        cout << "FAILED:"  << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1, 4, 2}, {1, 2, 4}, 2);
    test({2,5,1,2,5}, {10,5,2,1,5,2}, 3);
    test({1,3,7,1,7,5}, {1,9,2,5,1}, 2);
    test({1,1,2,1,2}, {1,3,2,3,1}, 3);
    test({1,1,3,5,3,3,5,5,1,1}, {2,3,2,1,3,5,3,2,2,1}, 5);
    test({3,1,4,1,1,3,5,1,2,2}, {4,1,5,2,1,1,1,5,3,1,1,1,2,3,1,4,3,5,5,3,1,2,3,2,4,1,1,1,5,3}, 9);
    test({15,14,1,7,15,1,12,18,9,15,1,20,18,15,16,18,11,8,11,18,11,11,17,20,16,20,15,15,9,18,16,4,16,1,13,10,10,20,4,18,17,3,8,1,8,19,14,10,10,12},
        {12,8,17,4,2,18,16,10,11,12,7,1,8,16,4,14,12,18,18,19,19,1,11,18,1,6,12,17,6,19,10,5,11,16,6,17,12,1,9,3,19,2,18,18,2,4,11,11,14,9,20,19,2,20,9,15,8,7,8,6,19,12,4,11,18,18,1,6,9,17,13,19,5,4,14,9,11,15,2,5,4,1,10,11,6,4,9,7,11,7,3,8,11,12,4,19,12,17,14,18},
        23);

    return 0;
}

