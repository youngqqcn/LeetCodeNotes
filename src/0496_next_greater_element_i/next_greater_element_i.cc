// author: yqq
// date: 2021-08-22 10:04:37
// descriptions: https://leetcode-cn.com/problems/next-greater-element-i
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
给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

 

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

提示：

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 10^4
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中
 
进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？


*/

class Solution
{
public:
    // 暴力搜索
    vector<int> nextGreaterElement_v1(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> result;
        for(int i = 0; i < nums1.size(); i++)
        {
            int j = 0;
            while(nums2[j] != nums1[i])
            {
                j++;
            }

            int target = -1;
            for(; j < nums2.size(); j++)
            {
                if(nums2[j] > nums1[i]) {
                    target = nums2[j];
                    break;
                }
            }
            result.push_back(target);
        }
        return result;
    }


    // 动态规划
    vector<int> nextGreaterElement_v2(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.empty()) return {};
        vector<int> result(nums1.size(), -1);
        if(nums1.size() < 2) return result;

        unordered_map<int, int> mp;
        for(int i = 0; i < nums1.size(); i++)
        {
            mp.insert(make_pair(nums1[i], i));
        }

        vector<int> dp(*max_element(nums2.begin(), nums2.end()) + 1, -1);
        int resultCount = 0;
        for(int i = nums2.size() - 2; i >= 0; i--)
        {
            int a = nums2[i], b = nums2[i + 1];
            if(a >= b) {
                dp[a] = dp[b];
                while(dp[a] < a && dp[a] >= 0) {
                    dp[a] = dp[dp[a]];
                }
            }else { // a < b
                dp[a] = b;
            }

            // 保存到result
            if(mp.find(a) != mp.end()) {
                result[mp[a]] = dp[a];
                resultCount++;
                if(resultCount == nums1.size()) {
                    break;
                }
            }
        }
        return result;
    }


    // 单调栈
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;

        stack<int> stk;
        unordered_map<int, int> nmap;

        for(int i = 0; i < nums2.size(); i++)
        {
            while(!stk.empty() && stk.top() < nums2[i])
            {
                // 更新栈顶元素
                int ntop = stk.top();
                stk.pop();
                nmap[ntop] = nums2[i];
            }
            stk.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++)
        {
            if(nmap.find(nums1[i]) !=  nmap.end()) {
                result.push_back(nmap[nums1[i]]);
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};

void test(vector<int> nums1, vector<int> nums2, vector<int> expected)
{
    Solution sol;
    auto result = sol.nextGreaterElement(nums1, nums2);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({4,1,2}, {1,3,4,2}, {-1,3,-1});
    test({2,4}, {1,2,3,4}, {3,-1});
    test({1,3,5,2,4}, {6,5,4,3,2,1,7}, {7,7,7,7,7});
    return 0;
}

