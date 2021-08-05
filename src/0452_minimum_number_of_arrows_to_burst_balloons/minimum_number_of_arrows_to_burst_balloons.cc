// author: yqq
// date: 2021-08-05 16:57:39
// descriptions: https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
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
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。
由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend，
 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。
 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

 
示例 1：

输入：points = [[10,16],[2,8],[1,6],[7,12]]
输出：2
解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
示例 2：

输入：points = [[1,2],[3,4],[5,6],[7,8]]
输出：4
示例 3：

输入：points = [[1,2],[2,3],[3,4],[4,5]]
输出：2
示例 4：

输入：points = [[1,2]]
输出：1
示例 5：

输入：points = [[2,3],[2,3]]
输出：1
 

提示：

1 <= points.length <= 10^4
points[i].length == 2
-2^31 <= xstart < xend <= 2^31 - 1

*/


class Solution
{
public:
    // 贪心: 抢尽量往右打(这样覆盖的范围大)
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if(points.size() < 2) return points.size();

        sort(points.begin(), points.end() , [](const vector<int>& a, const vector<int>& b)->bool {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1]; // 第1个值相同时, 第2个值小的在前
        });

        int rightEnd = points[0][1];
        int count = 1;
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > rightEnd) {
                count += 1;
                rightEnd = points[i][1];
            }else {
                // 前面那枪必须打在较小范围内
                rightEnd = min(points[i][1], rightEnd);
            }
        }
        return count;
    }
};

void test(vector<vector<int>> nums, int expected)
{
    Solution sol;
    int result = sol.findMinArrowShots(nums);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test( {{10,16},{2,8},{1,6},{7,12}}, 2);
    test( {{1,2},{3,4},{5,6},{7,8}}, 4);
    test( {{1,2},{2,3},{3,4},{4,5}}, 2);
    test( {{1,2}}, 1);
    test( {{2,3},{2,3}}, 1);
    test({{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}}, 2);
    test({{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}}, 2);

    return 0;
}

