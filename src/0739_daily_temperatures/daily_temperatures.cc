// author: yqq
// date: 2021-09-17 10:00:10
// descriptions: https://leetcode-cn.com/problems/daily-temperatures
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
请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:

输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:

输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:

输入: temperatures = [30,60,90]
输出: [1,1,0]
 

提示：

1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100

*/

class Solution {
public:
    // 暴力搜索 O(n^2)
    vector<int> dailyTemperatures_v1(vector<int>& temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size() - 1; i++)
        {
            for(int j = i + 1; j < temperatures.size(); j++)
            {
                if(temperatures[j] > temperatures[i]){
                    result[i] = j - i;
                    break;
                }
            }
        }
        return result;
    }

    // 单调栈
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector<int> result(temperatures.size(), 0);
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < temperatures.size(); i++)
        {
            while(!stk.empty() && temperatures[i] > temperatures[ stk.top() ])
            {
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }
};

void test(vector<int> temperature, vector<int> expected)
{
    Solution sol;
    auto result = sol.dailyTemperatures(temperature);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({73,74,75,71,69,72,76,73}, {1,1,4,2,1,1,0,0} );
    test({30, 40, 50, 60}, {1,1,1,0});
    test({30, 60, 90}, {1, 1, 0});
    return 0;
}

