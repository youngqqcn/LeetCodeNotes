// author: yqq
// date: 2021-09-03 14:10:14
// descriptions: https://leetcode-cn.com/problems/redundant-connection/
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
树可以看成是一个连通且 无环 的 无向 图。

给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，
且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。

请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。

 

示例 1：

          1 ----- 2
          |     /
          |   /
          | /
          3

输入: edges = [[1,2], [1,3], [2,3]]
输出: [2,3]

示例 2：

          2------1-------5
          |      |
          |      |
          3------4

输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
 

提示:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
edges 中无重复元素
给定的图是连通的 

*/


class Solution {
private:
    int find(vector<int>& parent, int index)
    {
        if(parent[index] != index) {
            // 递归找父节点
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }

    void join(vector<int>& parent, int index1, int index2)
    {
        parent[ find(parent, index1) ] = find(parent, index2);
    }

    void show(const vector<int>& parent)
    {
        for_each(parent.begin(), parent.end(), [](int n){
            cout << n << ", ";
        });
        cout << endl;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        // 并查集
        int nodesCount = edges.size();
        vector<int> parent(nodesCount + 1, 0);
        for(int i = 0; i < parent.size(); i++)
        {
            parent[i] = i;
        }

        for(auto item: edges)
        {
            show(parent);
            if( find(parent, item[0]) == find(parent, item[1]) ) {
                return item;
            }
            else {
                join(parent, item[0], item[1]);
            }
        }

        return {};
    }
};

void test(vector<vector<int> > edges, vector<int> expected)
{
    Solution sol;
    auto result = sol.findRedundantConnection(edges);
    if(result != expected )
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({{1,2}, {1,3}, {2,3}}, {2, 3});
    test({{1,2}, {2,3}, {3,4}, {1, 4}, {1,5}}, {1, 4});
    return 0;
}

