// author: yqq
// date: 2021-09-15 10:27:44
// descriptions: https://leetcode-cn.com/problems/redundant-connection-ii
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
在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。
该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。

输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。
附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，
用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。

返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1：



   1 ──────────► 3
    │           ▲
    │           │
    │           │
    │           │
    ▼  ─────────┘
    2



输入：edges = [[1,2],[1,3],[2,3]]
输出：[2,3]

示例 2：

    2─────────►3
    ▲          │
    │          │
    │          │
    │          ▼
    1◄─────────4
    │
    │
    ▼
    5


输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
输出：[4,1]


提示：

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ui, vi <= n


*/

class Solution {
private:
    static const int m_size =1100;
    int m_father[m_size];

    void initFather()
    {
        for(int i = 0; i <m_size; ++i) {
            m_father[i] = i;
        }
    }

    int find(int u)
    {
        if(u == m_father[u]) {
            return u;
        }
        m_father[u] = find(m_father[u]);
        return m_father[u];
    }

    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if(u != v) {
            m_father[v] = u;
        }
    }

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }

    vector<int> getRemoveEdge(const vector<vector<int>>& edges)
    {
        initFather();
        for(int i = 0; i < edges.size(); i++)
        {
            if(same(edges[i][0], edges[i][1])) { // 有向环
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge)
    {
        initFather();
        for(int i = 0; i < edges.size(); i++)
        {
            if(i == deleteEdge) continue;
            if(same(edges[i][0], edges[i][1])) { // 有向环
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }


public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int inDegree[m_size] = {0};
        for(int i = 0; i < edges.size(); i++)
        {
            // 入度
            inDegree[ edges[i][1] ] += 1;
        }

        // 找出入度为2的节点所对应的边的索引
        vector<int> vctTwoDegreeEdge;
        for(int i = edges.size() - 1; i >= 0; i--)
        {
            if(inDegree[edges[i][1]] == 2) {
                vctTwoDegreeEdge.push_back(i);
            }
        }

        // 有入度为2的节点
        if(vctTwoDegreeEdge.size() > 0)
        {
            if(isTreeAfterRemoveEdge(edges, vctTwoDegreeEdge[0])) {
                return edges[vctTwoDegreeEdge[0]];
            }
            return edges[vctTwoDegreeEdge[1]];
        }

        // 没有入度为2的， 存在有向环
        return getRemoveEdge(edges);
    }
};

void test(vector<vector<int>> edges, vector<int> expected)
{
    Solution sol;
    vector<int> result = sol.findRedundantDirectedConnection(edges);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({{1,2},{1,3},{2,3}}, {2, 3});
    test({{1,2},{2,3},{3,4},{4,1},{1,5}}, {4, 1});
    return 0;
}

