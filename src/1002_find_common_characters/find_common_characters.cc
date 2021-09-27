// author: yqq
// date: 2021-09-27 15:10:47
// descriptions: https://leetcode-cn.com/problems/find-common-characters/
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
给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），
并以数组形式返回。你可以按 任意顺序 返回答案。
 

示例 1：

输入：words = ["bella","label","roller"]
输出：["e","l","l"]

示例 2：

输入：words = ["cool","lock","cook"]
输出：["c","o"]
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 由小写英文字母组成

*/


class Solution
{
public:
    vector<string> commonChars(vector<string>& words)
    {
        // 一个二维数组, 记录 a～z 26个字母的出现频率
        vector<vector<int>> m(words.size(), vector<int>(26, 0));
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                char ch = words[i][j];
                m[i][ ch - 'a' ]++;
            }
        }

        vector<string> result;
        for(int i = 0; i < m[0].size(); i++)
        {
            int minCount = INT_MAX;
            for(int j = 0;  j < m.size(); j++)
            {
                minCount = std::min(m[j][i], minCount);
            }

            for(int j = 0; minCount != INT_MAX && j < minCount; j++)
            {
                string s;
                s.append(1, i + 'a');
                if(!s.empty()) {
                    result.push_back( "" + s);
                }
            }
        }
        return result;
    }
};

void test(vector<string> words, vector<string> expected)
{
    Solution sol;
    auto result = sol.commonChars(words);
    if(!std::equal(result.begin(), result.end(), expected.begin(), expected.end()))
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({"bella","label","roller"}, {"e","l","l"});
    test({"cool","lock","cook"}, {"c","o"});
    return 0;
}

