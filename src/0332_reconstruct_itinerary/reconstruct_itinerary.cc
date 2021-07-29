// author: yqq
// date: 2021-07-28 18:35:23
// descriptions: https://leetcode-cn.com/problems/reconstruct-itinerary
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
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。

所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。

例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。

示例 1：

┌───────┐     ┌───────┐     ┌──────┐
│  MUC  ├────►│   LHR ├────►│ SFO  │
└───────┘     └───────┘     └──┬───┘
    ▲                          │
    │                          │
┌───┴───┐                   ┌──▼───┐
│  JFK  │                   │ SJC  │
└───────┘                   └──────┘


输入：tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
输出：["JFK","MUC","LHR","SFO","SJC"]

示例 2：

┌───────┐
│       ├─────────────────────┐
│ SFO   │                     │
└───────┘◄──────────────────┐ │
   ▲                        │ │
   │                        │ │
   │                        │ │
   │                        │ │
┌──┴────┐              ┌────┴─▼─┐
│       ├──────────────►        │
│ JFK   │              │  ATL   │
└───────┘◄────────── ──┴────────┘

输入：tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"] ，但是它字典排序更大更靠后。


*/

class Solution
{
private:
    // unordered_map<出发机场, map<到达机场, 航班次数>> targets
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& result)
    {
        if (result.size() == ticketNum + 1) {
            return true;
        }
        for (pair<const string, int>& target : targets[result[result.size() - 1]])
        {
            if (target.second > 0 ) {
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum, result)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        targets.clear();
        vector<string> result;
        for (const vector<string>& vec : tickets) {
            targets[vec[0]][vec[1]]++;
        }
        result.push_back("JFK");
        backtracking(tickets.size(), result);
        return result;
    }
};



void test(vector<vector<string>> targets, vector<string> expected)
{
    Solution sol;
    auto result = sol.findItinerary(targets);

    if(expected.size() != result.size())
    {
        cout << "FAILED" << endl;
        return;
    }

    if(expected != result)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}}, {"JFK","ATL","JFK","SFO","ATL","SFO"} );
    test({{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}}, {"JFK","MUC","LHR","SFO","SJC"});
    return 0;
}

