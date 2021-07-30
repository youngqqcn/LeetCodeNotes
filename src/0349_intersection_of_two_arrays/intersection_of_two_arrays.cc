// author: yqq
// date: 2021-07-30 14:11:28
// descriptions: https://leetcode-cn.com/problems/intersection-of-two-arrays
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

给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

*/

class Solution {
public:
    vector<int> intersection_v1(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> result;
        auto last = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                    std::inserter(result, result.begin())); // 插入迭代器
        return result;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;

        for(int p1 = 0, p2 = 0; p1 < nums1.size() && p2 < nums2.size(); )
        {
            if(nums1[p1] == nums2[p2])
            {
                int value = nums1[p1];
                result.push_back(value);
                while(p1 < nums1.size() && nums1[p1] == value) { p1++; }
                while(p2 < nums2.size() && nums2[p2] == value) { p2++; }
            }
            else
            {
                if(nums1[p1] < nums2[p2]) {
                    p1++;
                } else {
                    p2++;
                }
            }
        }
        return result;
    }
};

void test(vector<int> nums1, vector<int> nums2,  set<int> expected)
{
    Solution sol;
    auto result = sol.intersection(nums1, nums2);
    if(result.size() != expected.size())
    {
        cout << "FAILED" << endl;
        return;
    }
    for(auto item : result)
    {
        auto it = expected.find(item);
        if(it == expected.end()) {
            cout << "FAILED" << endl;
            return;
        }
        expected.erase(it);
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,2,1}, {2,2}, {2});
    test({4,9,5}, {9,4,9,8,4}, {9, 4});
    return 0;
}

