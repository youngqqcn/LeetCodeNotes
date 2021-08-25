// author: yqq
// date: 2021-06-14 16:06:07
// descriptions: https://leetcode-cn.com/problems/edit-distance/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 

提示：

0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成

*/

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        // 1.确定dp数组下标含义, dp[i][j] 表示以word1[i-1]结尾的子串 与 word2[j-1]结尾的子串 的最小编辑距离
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        // 2.确定递推公式:
        //  if( word1[i-1] == word2[j-1])   dp[i][j] = dp[i-1][j-1]
        //  if( word1[i-1] != word2[j-1])
        //     在word1[i-1]增加:                    dp[i][j] = dp[i-1][j] + 1
        //                删除(相当于在word2中添加):  dp[i][j] = dp[i][j-1] + 1
        //                替换:                     dp[i][j] = d[i-1][j-1] + 1
        //       取最小  min(dp[i-1][j], dp[i][j-1], d[i-1][j-1]) + 1

        // 3.确定dp数组初始化, dp[0][0] = 0, dp[i][0] = i, dp[0][j] = j
        for(int i = 0; i < dp.size(); i++) dp[i][0] = i;
        for(int i = 0; i < dp[0].size(); i++) dp[0][i] = i;

        // 4.确定dp数组遍历顺序, 从上到下, 从左到右
        for(int i = 1; i < dp.size(); i++){
            for(int j = 1; j < dp[i].size(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j- 1];
                }else {
                    dp[i][j] = min({dp[i-1][j],  dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
            }
        }

        // 5.举例(略)

        return dp[word1.size()][word2.size()];
    }
};



void test(string  word1, string word2, int expected)
{
    Solution sol;
    int ret = sol.minDistance(word1, word2 );
    if(ret != expected){
        cout << "FAILED" << " , result is : " << ret << endl;
    }else {
        cout << "PASSED" << endl;
    }
}


int main()
{
    test("horse", "ros", 3);
    test("intention", "execution", 5);
    test("", "a", 1);
    cout << "hello world" << endl;
    return 0;
}

