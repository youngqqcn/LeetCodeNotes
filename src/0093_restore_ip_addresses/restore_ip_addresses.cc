// author: yqq
// date: 2021-06-16 11:41:14
// descriptions: https://leetcode-cn.com/problems/restore-ip-addresses/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <stdlib.h> // atoi
using namespace std;


/*
给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。

有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。


示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

提示：

0 <= s.length <= 3000
s 仅由数字组成
*/


// 思路:
//   1. 截取字符串为4个子串, 使得每个子串都符合规则, 列出所有可能性,
//          使用回溯法


class Solution {
private:

    vector<string> result;
    vector<string> nums;
    int count = 0;

    void backtracking(const string &s, int startIndex)
    {
        // 递归终止
        // 符合规则, 或者 长度超出
        if(nums.size() == 4 && count == s.size())
        {
            string ip = "";
            for(int i = 0; i < nums.size(); i++){
                if( 0 != i) {
                    ip += ".";
                }
                ip += nums[i];
            }
            result.push_back(ip);
            return;
        }

        for (int i = startIndex; i - startIndex <= 3 && i < s.size(); i++)
        {
            string sub = s.substr(startIndex, i - startIndex + 1);
            // 不能有前缀 '0' , 比如 010, 001, 01
            if(1 < sub.size() && '0' == sub[0]  ){
                continue;
            }

            int n  = atoi(sub.c_str());
            if( 0 <= n && n <= 255) {
                nums.push_back(sub);
                count += sub.size();

                backtracking(s, i+1);

                // 回溯
                nums.pop_back();
                count -= sub.size();
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        nums.clear();
        count = 0;
        result.clear();

        // 按照 IP规则, 每个整数属于 [0, 255], 所以, 最长是 3 * 4 = 12个字符,
        // 如果s超过12, 则非法, 返回空集即可
        if(s.size() > 12) {
            return result;
        }
        backtracking(s, 0);
        return result;
    }
};


void test(string s, set<string> expected )
{
    Solution sol;
    auto result = sol.restoreIpAddresses(s);
    if(result.size() != expected.size()) {
        cout << "FAILED" << endl;
        return;
    }

    for(auto item : result) {
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
    test("25525511135", {"255.255.11.135","255.255.111.35"});
    test("0000", {"0.0.0.0"});
    test("1111", {"1.1.1.1"});
    test("010010", {"0.10.0.10","0.100.1.0"});
    test("101023", {"1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"});
    test("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111", {});

    cout << "hello world" << endl;
    return 0;
}

