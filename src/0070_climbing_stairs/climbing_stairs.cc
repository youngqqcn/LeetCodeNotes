// author: yqq
// date: 2021-06-13 15:10:31
// descriptions: https://leetcode-cn.com/problems/climbing-stairs/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    // DP , 动态规划
    int climbStairs_DP(int n) {
        if(0 == n) return 0;
        // if(n <= 2) return 1;
        // 1.dp数组, dp[i] 表示 从台阶0到台阶i的方法数
        // 2.因为每步可以爬1或2步, 所以递推公式: dp[i] = dp[i-1] + dp[i-2]
        vector<int> dp(n+1, 0);

        // 3.dp数组初始化, dp[0] = 1, dp[1] = 1
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }


    // recursive(leetcode 超出时间限制)
    int climbStairs_recursive(int n) {
        if(n < 2) return 1;
        return climbStairs_recursive(n - 1) + climbStairs_recursive(n - 2);
    }

    // 1,1,2,3,5,8,..... fibonacii数列
    int climbStairs(int n) {
        int fibnum = 0;
        int a = 1, b = 1;
        if(n < 2) return 1;
        for(int i = 2; i < n+1; i++){
            fibnum = a + b;
            a = b;
            b = fibnum;
        }
        return fibnum;
    }


    int climbStairs_formular(int n)
    {
        // TODO: 使用fibonacii通项公式: an = [(2/√5+1)-1/(√5+1/2)ⁿ]/√5
        return 0;
    }


};


void test(int n, int expected)
{
    Solution sol;
    int result = sol.climbStairs(n);
    if(result != expected){
        cout << "FAILED" << " result is " << result << endl;
    }else{
        cout << "PASSED" << endl;
    }

}


int main()
{
    test(2, 2);
    test(3, 3);
    cout << "hello world" << endl;
    return 0;
}

