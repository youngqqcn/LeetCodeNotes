// author: yqq
// date: 2021-06-27 15:42:19
// descriptions: https://leetcode-cn.com/problems/candy/
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
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。

那么这样下来，老师至少需要准备多少颗糖果呢？

 

示例 1：

输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：[1,2,2]
输出：4
解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

*/

class Solution
{
public:
    int dpFunc(vector<int> ratings, int i, vector<int> &dp)
    {
        // 递归终止
        if(ratings[i] == 0) return 1;
        if(i == 0 && ratings.size() >= 2 && ratings[i] < ratings[i+1]) return 1;
        if(i >= 1 && ratings[i-1] > ratings[i]  &&  i+1 < ratings.size() && ratings[i] < ratings[i+1]) return 1;
        if(i == ratings.size() - 1 && i > 1 && ratings[i-1] > ratings[i]) return 1;
        if(i > 1 && ratings[i-1] == ratings[i] && i+1 < ratings.size() && ratings[i] == ratings[i+1]) return 1;


        if (ratings[i - 1] < ratings[i] && ratings[i] < ratings[i + 1])
        {
            dp[i] = min(dp[i - 1] + 1, dp[i + 1] - 1);
        }
    }

    int candy(vector<int> &ratings)
    {
        vector<int> dp(ratings.size());
        ratings.insert(ratings.begin(), -1);
        ratings.insert(ratings.end() - 1, -1);
        // 思路:
        //  r[i-1] > r[i] < r[i+1]   ==> dp[i] = 1
        //  r[i] == 0  ===> d[i] = 1
        //  r[i]  i == size   r[i] == r[i-1]  ===> dp[i] = 1
        //  i == 0   r[i] < r[i+1]   ==> dp[i] = 1   i+1 != size-1 ==> dp[i+1] = 2
        //  r[i-1] == r[i] == r[i+1]  ==> dp[i] = 1

        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i - 1] < ratings[i] && ratings[i] < ratings[i + 1])
            {
                dp[i] = min(dp[i - 1] + 1, dp[i + 1] - 1);
            }
            else if (ratings[i - 1] < ratings[i] && ratings[i] > ratings[i + 1])
            {
                dp[i] = max(dp[i + 1] + 1, dp[i - 1] + 1);
            }
            else if (ratings[i - 1] > ratings[i] && ratings[i] < ratings[i + 1])
            {
                dp[i] = INT32_MIN; //min( dp[i+1] + 1, dp[i-1] + 1) ;
            }
            else if (ratings[i - 1] == ratings[i] && ratings[i] < ratings[i + 1])
            {
                dp[i] =
            }
        }

        return 0;
    }
};

void test(vector<int> ratings, int expected)
{
    Solution sol;
    auto result = sol.candy(ratings);
    if (result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
    return;
}

int main()
{
    test({1, 0, 2}, 5);                 // 2 1  2
    test({1, 2, 2}, 4);                 // 1 2 1
    test({1, 3, 2, 2, 1}, 7);           // 1 2 1 2 1
    test({1, 2, 87, 87, 87, 2, 1}, 13); // 1 2 3 1 3 2 1
    test({29, 51, 87, 87, 72, 12}, 12); // 1 2 3 3 2 1
    test({1, 3, 4, 5, 2}, 11);          // 1 2 3 4 1
    test({1, 2, 4, 4, 4, 3}, 10);       // 1 2 3 1 2 1
    cout << "hello world" << endl;
    return 0;
}
// 思路:
//  r[i-1] > r[i] < r[i+1]   ==> dp[i] = 1
//  r[i] == 0  ===> d[i] = 1
//  r[i]  i == size   r[i] == r[i-1]  ===> dp[i] = 1
//  i == 0   r[i] < r[i+1]   ==> dp[i] = 1   i+1 != size-1 ==> dp[i+1] = 2
//  r[i-1] == r[i] == r[i+1]  ==> dp[i] = 1
