// author: yqq
// date: 2021-07-23 18:26:00
// descriptions: https://leetcode-cn.com/problems/combination-sum-iii
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
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 

示例 1:
输入: k = 3, n = 7
输出: [[1,2,4]]


示例 2:
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

*/

class Solution {
private:
    int sum ;
    set<vector<int>> result;
    vector<int> path;

public:

    void backtracking_1(int start, int k, int n)
    {
        if(sum == n && path.size() == k) {
            result.insert(path);
            return;
        }

        for(int i = start; i <= 9; i++)
        {
            sum += i;
            path.push_back(i);
            backtracking(i+1, k, n);

            // 回溯
            sum -= i;
            path.pop_back();
        }
    }

     void backtracking(int start, int k, int n)
    {
        if(sum > n) return;

        if(sum == n && path.size() == k) {
            result.insert(path);
            return;
        }

        // k - path.size()  是还需要的元素个数
        for(int i = start; i <= 9 - (k - path.size()) + 1; i++)
        {

            sum += i;
            path.push_back(i);
            backtracking(i+1, k, n);

            // 回溯
            sum -= i;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        // clean
        // result.clear();

        sum = 0;
        path.clear();

        backtracking(1, k, n);
        return vector<vector<int>>(result.begin(), result.end());
    }
};

void test(int k, int n, set<vector<int>> expected )
{
    Solution sol;
    auto result  = sol.combinationSum3(k, n);
    if(result.size() != expected.size()) {
        cout << "FAILED" << endl;
        return;
    }

    for(int i = 0; i < result.size(); i++)
    {
        sort(result[i].begin(), result[i].end());
        auto it = expected.find(result[i]);
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
    test(3, 7, {{1,2,4}});
    test(3, 9, {{1, 2, 6}, {1, 3, 5}, {2, 3, 4}});

    return 0;
}

