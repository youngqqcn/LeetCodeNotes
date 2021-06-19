// author: yqq
// date: 2021-06-19 14:12:02
// descriptions: https://leetcode-cn.com/problems/distinct-subsequences/
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
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。

 

示例 1：

输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)
rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2：

输入：s = "babgbag", t = "bag"
输出：5
解释：
如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。
(上箭头符号 ^ 表示选取的字母)
babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
 

提示：

0 <= s.length, t.length <= 1000
s 和 t 由英文字母组成

*/



/*
思路: 使用动态规划

         r     a     b     b     i     t
    1 |  0  |  0  |  0  |  0  |  0  |  0  |
r | 1 |  1  |  0  |  0  |  0  |  0  |  0  |
a | 1 |  1  |  1  |  0  |  0  |  0  |  0  |
b | 1 |  1  |  1  |  1  |  0  |  0  |  0  |
b | 1 |  1  |  1  |  2  |  1  |  0  |  0  |
b | 1 |  1  |  1  |  3  |  3  |  0  |  0  |
i | 1 |  1  |  1  |  3  |  3  |  3  |  0  |
t | 1 |  1  |  1  |  3  |  3  |  3  |  3  |


1.关于dp数组下标含义的定义:
dp[row][col] 表示 s[row] 与 t[col] 不同子序列的个数

2.初始化
dp[row][0] = 1
dp[0][col] = 0, 其中 col >= 1

if( row < col) {
    dp[row][col] = 0
}

3. 递推公式

if(col >= row) {
    if(s[row - 1] == t[col - 1]) {
        dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col]; // 斜上方 + 上方
    } else {
        dp[row][col] = dp[row - 1][col]; // 上方
    }
}

4. 遍历顺序:  从上到下, 从左到右, 按列遍历

5. 上面已经举例

*/


class Solution {
public:
    int numDistinct(string s, string t) {
        // if(t == "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys") {
        //     return 777;
        // }

        // 处理leetcode 乱搞的测试用例
        if(t.size() > s.size()) return 0;
        if(t.size() == s.size()) {
            return (t == s) ? true : false;
        }

        //
        vector<vector<int64_t>> dp(s.size() + 1, vector<int64_t>(t.size() + 1, 0));
        // vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int row = 0; row <= s.size(); row++) {
            dp[row][0] = 1;
        }
        // 本来就是0
        // for(int col = 1; col <= t.size(); col++) {
        //     dp[0][col] = 0;
        // }

        for(int col = 1; col <= t.size(); col++) {
            for(int row = col; row <= s.size(); row++) {
                // 这行代码是剪枝操作,因为下面的对于计算最终值无用
                if(row > s.size() - (t.size() - col))
                    break ;

                if(s[row - 1] == t[col - 1]) {
                    // 斜上方 + 上方
                    dp[row][col] = dp[row - 1][col - 1] + dp[row - 1][col];
                } else {
                    // 上方
                    dp[row][col] = dp[row - 1][col];
                }
            }
        }

        return dp[s.size()][t.size()];
    }
};

void test(string s, string t, int expected)
{
    Solution sol;
    auto result = sol.numDistinct(s, t);
    if(result != expected)
    {
        cout << "FAILED" << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test("rabbbit", "rabbit", 3);
    test("babgbag", "bag", 5);

    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    test(s, t, 543744000);
    // cout << "hello world" << endl;
    return 0;
}

