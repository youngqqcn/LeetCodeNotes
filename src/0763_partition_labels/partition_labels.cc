// author: yqq
// date: 2021-09-18 10:10:51
// descriptions: https://leetcode-cn.com/problems/partition-labels
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
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 
提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。
*/


class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        // 记录最大下标
        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++)
        {
            m[s[i]] = max(m[s[i]], i);
        }

        vector<int> result;
        int i = 0;
        for(; i < s.length(); )
        {
            int end = m[s[i]];
            for(int j = i + 1; j < end; j++)
            {
                end = max(end, m[s[j]]);
            }
            result.push_back(end - i + 1);
            i = end + 1;
        }

        return result;
    }
};

void test(string s, vector<int> expected)
{
    Solution sol;
    auto result = sol.partitionLabels(s);
    if(result.size() != expected.size() || !std::equal(result.begin(), result.end(), expected.begin()))
    {
        cout << "FAILED" << endl;
        return;
    }

    cout << "PASSED" << endl;
}

int main()
{
    test("ababcbacadefegdehijhklij", {9,7,8});
    return 0;
}

