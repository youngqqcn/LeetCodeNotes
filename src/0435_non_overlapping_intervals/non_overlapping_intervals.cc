// author: yqq
// date: 2021-08-04 15:09:26
// descriptions: https://leetcode-cn.com/problems/non-overlapping-intervals
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
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:

输入: [[1,2], [1,2], [1,2]]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:

输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

*/

class Solution
{
public:
    // 贪心: 按照右边界排序,  优先选择右区间小且不会导致重合的区间   (太妙了!)
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        // 按照右边界
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>&b)->bool {
            return a[1] < b[1];
        });

        vector<int> last = intervals[0];
        int count = 1; // 不重合的区间
        for(int i = 1; i < intervals.size(); i++)
        {
            // 找到下一个与last区间不重合的区间
            if(intervals[i][0] >= last[1]) {
                last = intervals[i];
                count++;
            }
        }
        return intervals.size() - count;
    }
};


void test(vector<vector<int>> intervals, int expected)
{
    Solution sol;
    if( expected != sol.eraseOverlapIntervals(intervals) )
    {
        cout << "FAILED" << endl;
        return;
    }

    cout << "PASSED" << endl;
}

int main()
{
    test({{1,2}, {2,3}, {3,4}, {1,3}}, 1);
    test({{1,2}, {1,2}, {1,2}}, 2);
    test({{1,2}, {2,3}}, 0);
    return 0;
}

