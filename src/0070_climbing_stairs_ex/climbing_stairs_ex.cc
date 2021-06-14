// author: yqq
// date: 2021-06-14 13:57:55
// descriptions:
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;



class Solution {
public:
    // DP , 动态规划
    int climbStairs(int n)
    {
        int m = 2;
        if(0 == n) return 0;
        // if(n <= 2) return 1;
        // 1.dp数组, dp[i] 表示 从台阶0到台阶i的方法数
        // 2.因为每步可以爬1,2,3....m步, 所以递推公式: dp[i] = dp[i-m] + dp[i-m-1] + ... + dp[i-2] + dp[i-1]
        vector<int> dp(n+1, 0);

        // 3.dp数组初始化, dp[0] = 1, dp[1] = 1
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= m && i - j >= 0; j++) {
                sum += dp[i - j];
            }
            dp[i] = sum;
        }
        return dp[n];
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

