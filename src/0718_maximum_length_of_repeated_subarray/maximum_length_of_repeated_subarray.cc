// author: yqq
// date: 2021-09-16 14:26:50
// descriptions: https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
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
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

 

示例：

输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。
 

提示：

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/

class Solution {
public:
    // 暴力搜索
    int findLength_v1(vector<int>& nums1, vector<int>& nums2)
    {
        int maxLen = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                int len = 0;
                int curj = j;
                for(int curi = i, curj = j;
                    curi < nums1.size()
                    && curj < nums2.size()
                    && nums1[curi] == nums2[curj] ; curi++, curj++)
                {
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }


    // 动态规划
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int maxLen = 0;
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));

        for(int i = 1; i <= nums1.size(); i++)
        {
            for(int j = 1; j <= nums2.size(); j++)
            {
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i- 1][j - 1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};


void test(vector<int> nums1, vector<int> nums2, int expected)
{
    Solution sol;
    int result = sol.findLength(nums1, nums2);
    if(result != expected)
    {
        cout << "FAILED" << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,3,2,1}, {3,2,1,4,7}, 3);
    test({0,0,0,0,0}, {0,0,0,0,0}, 5);
    test({0,0,0,0,1}, {1,0,0,0,0}, 4);
    test({1,2,3,2,1}, {3,2,1,4}, 3);
    test({1,2,3,2,8}, {5,6,1,4,7}, 1);

    return 0;
}

