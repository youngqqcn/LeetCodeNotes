// author: yqq
// date: 2021-08-02 10:11:08
// descriptions: https://leetcode-cn.com/problems/ransom-note
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
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)

 

示例 1：

输入：ransomNote = "a", magazine = "b"
输出：false
示例 2：

输入：ransomNote = "aa", magazine = "ab"
输出：false
示例 3：

输入：ransomNote = "aa", magazine = "aab"
输出：true
 

提示：

你可以假设两个字符串均只含有小写字母。
*/

class Solution
{
public:
    // 思路: 将ransomNote 和 magazine 字母做map,
    //      如果 magazine字母大于等于ransomNote的map, 那么就说可以组成
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int>  mMap;
        for(int i = 0; i < magazine.size(); i++)
        {
            mMap[magazine[i]] += 1;
        }

        for(int i = 0; i < ransomNote.size(); i++)
        {
            if(mMap[ ransomNote[i]] - 1 < 0) {
                return false;
            }
            mMap[ ransomNote[i]] -= 1;
        }
        return true;
    }
};

void test(string ransomNote, string magazine, bool expected)
{
    Solution sol;
    if(expected != sol.canConstruct(ransomNote, magazine))
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("a", "b", false);
    test("aa", "ab", false);
    test("aa", "aab", true);
    return 0;
}

