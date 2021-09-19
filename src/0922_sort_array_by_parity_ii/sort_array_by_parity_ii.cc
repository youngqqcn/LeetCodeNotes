// author: yqq
// date: 2021-09-19 10:28:43
// descriptions:https://leetcode-cn.com/problems/sort-array-by-parity-ii
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
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000


*/


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        vector<int> odd, even;
        for(int n : nums)
        {
            if(0 != (n & 1)) {
                odd.push_back(n);
            }
            else {
                even.push_back(n);
            }
        }

        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(0 != (i & 1)) {
                result.push_back(odd.back()); odd.pop_back();
            }
            else {
                result.push_back(even.back()); even.pop_back();
            }
        }
        return result;
    }
};

void test(vector<int> nums)
{
    Solution sol;
    auto result = sol.sortArrayByParityII(nums);
    if(result.size() != nums.size())
    {
        goto FAIL;
    }

    for(int i = 0; i < result.size(); i++)
    {
        if(!((0 != (i & 1) && 0 != (result[i] & 1) )
            || (0 == (i & 1) && 0 == (result[i] &1)) )) {
            goto FAIL;
        }
    }

    cout << "PASSED" << endl;
    return;

FAIL:
    cout << "FAILED" << endl;
    return;
}

int main()
{
    test({4,2,5,7});

    return 0;
}

