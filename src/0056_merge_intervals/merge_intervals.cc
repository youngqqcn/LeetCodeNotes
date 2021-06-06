// author: yqq
// date: 2021-06-05 16:54:08
// descriptions: https://leetcode-cn.com/problems/merge-intervals/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1：

输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

class Solution {
public:
    vector<vector<int>> merge_v1(vector<vector<int>>& vct) 
    {
        // 去重
        set<vector<int>> tmp(vct.begin(), vct.end());
        vector<vector<int>> intervals(tmp.begin(), tmp.end());

        // 排序
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ 
            return a[0] < b[0];
        });

        auto slow = intervals.begin();
        auto fast = intervals.begin() + 1;
        int removed = 0;
        int rawSize = intervals.size();
        for(auto it = intervals.begin(); it != intervals.end();  ){
            if(it == intervals.end() || fast == intervals.end() || (*fast).empty()){
                break;
            }

            if((*slow)[1] > (*fast)[0]){
                if((*slow)[1] < (*fast)[1]){
                    // 合并
                    (*slow)[1] = (*fast)[1];
                }
                it = intervals.erase(fast);
                fast = it;
            }else if((*slow)[1] == (*fast)[0]){
                // 合并
                (*slow)[1] = (*fast)[1];
                it = intervals.erase(fast);
                fast = it;
            }else {
                slow = it;
                it++;
                fast = it;
            }
        }

        return intervals;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        // 去重
        // set<vector<int>> tmp(vct.begin(), vct.end());
        // vector<vector<int>> intervals(tmp.begin(), tmp.end());

        // 排序,  lambda使用 const 引用会大大提升sort的效率
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){ 
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 0; i < intervals.size(); i++)
        {
            if(result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};

void test(vector<vector<int>> intervals, vector<vector<int>> expected)
{
    Solution solution;
    auto result = solution.merge(intervals);
    if(result != expected){
        cout << "FAILED" << endl;
        return;
    }else{
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({{2,6},{1,3},{8,10},{15,18}}, {{1,6},{8,10},{15,18}});
    test( {{1,4},{4,5}}, {{1,5}});
    test({{1,4},{0,2},{3,5}}, {{0, 5}});
    test({{2,3},{4,5},{6,7},{8,9},{1,10}}, {{1,10}});
    test({{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}}, {{1,3},{4,7}});

    // cout << "hello world" << endl;
    return 0;
}

