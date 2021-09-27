// author: yqq
// date: 2021-09-27 16:15:50
// descriptions: https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/
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
给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，
然后总共重复这个过程 K 次。（我们可以多次选择同一个索引 i。）

以这种方式修改数组后，返回数组可能的最大和。
 

示例 1：

输入：A = [4,2,3], K = 1
输出：5
解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。

示例 2：

输入：A = [3,-1,0,2], K = 3
输出：6
解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。

示例 3：

输入：A = [2,-3,-1,5,-4], K = 2
输出：13
解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
 

提示：

1 <= A.length <= 10000
1 <= K <= 10000
-100 <= A[i] <= 100

*/


class Solution
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());

        // 1.如果有负数，优先把小的负数变成正数
        // 2.如果都是正数，则将小的正数变成负数

        for(int i = 0; k > 0; i++)
        {
            if(i < nums.size() && nums[i] < 0)  {
                nums[i] = -nums[i];
                k--;
            }else if(k > 0){
                if(k % 2 == 1) {
                    *std::min_element(nums.begin(), nums.end()) *= (-1);
                }
                break;
            }
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};

void test(vector<int> nums, int k, int expected)
{
    Solution sol;
    auto result = sol.largestSumAfterKNegations(nums, k);
    if(result != expected)
    {
        cout << "FAILED: " << result << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({4,2,3}, 1, 5);
    test({3,-1,0,2}, 3, 6);
    test({2,-3,-1,5,-4}, 2, 13);
    test({-4,-2,-3}, 4, 5);
    return 0;
}


