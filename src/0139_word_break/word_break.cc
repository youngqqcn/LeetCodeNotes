// author: yqq
// date: 2021-06-30 18:41:22
// descriptions: https://leetcode-cn.com/problems/word-break
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
using namespace std;


/*

给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

    }
};


void test(string s, vector<string> wordDict, bool expected)
{
    Solution sol;
    if(expected == sol.wordBreak(s, wordDict))
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}



int main()
{
    test("leetcode", {"leet", "code"}, true);
    test("applepenapple", {"apple", "pen"}, true);
    test("catsandog", {"cats", "dog", "sand", "and", "cat"}, false);
    cout << "hello world" << endl;
    return 0;
}

