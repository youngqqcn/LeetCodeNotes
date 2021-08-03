// author: yqq
// date: 2021-08-03 14:09:15
// descriptions: https://leetcode-cn.com/problems/queue-reconstruction-by-height
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
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

 

示例 1：

输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
示例 2：

输入：people = [[6,0],[5,0],[4,0],[3,2],[2,2],[1,4]]
输出：[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

提示：

1 <= people.length <= 2000
0 <= hi <= 10^6
0 <= ki < people.length
题目数据确保队列可以被重建
*/


/*

[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]

按照身高排序：
[4,4] [5,0] [5,2] [6,1] [7,1] [7,0]

相同身高的再按照第2个值排序
[4,4] [5,0] [5,2] [6,1] [7,1] [7,0]


*/

class Solution {
private:
    #define NIL  -1

    struct HeightCmp
    {
        bool operator () (const vector<int>& a, const vector<int>& b)
        {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1]; // 升序
        }
    };

    struct HeightCmpV2
    {
        bool operator () (const vector<int>& a, const vector<int>& b)
        {
            if(a[0] != b[0]) return a[0] > b[0];  // 身高高的在前
            return a[1] < b[1]; // 相同身高, 第2个值小的在前
        }
    };

    int beforeEmptyCount(int n, int index, const vector<vector<int>> &result)
    {
        int count = 0;
        for(int i = 0; i < index; i++)
        {
            if(n <= result[i][0] || (NIL == result[i][0] && NIL == result[i][1])) {
                count += 1;
            }
        }
        return count;
    }
public:
    // 构造一个长度为n的数组, 其中 n == people.size()
    // 获取最小的元组(val, idx), 其中元组的idx就是开始查找"空位"的下标
    // 如果idx所在下标已经被占,则向后查找,直到找到找到"空位"
    vector<vector<int>> reconstructQueue_v1(vector<vector<int>>& people)
    {
        vector<vector<int>> result(people.size(), vector<int>(2, NIL));
        sort(people.begin(), people.end(), HeightCmp());
        for(int i = 0; i < people.size(); i++)
        {
            vector<int> tp = people[i];
            int idx = tp[1];
            for(int j = idx; j < result.size(); j++)
            {
                if(NIL == result[j][0] && NIL == result[j][1] ) {
                    if( beforeEmptyCount(tp[0], j, result) >= idx || i == people.size() -1) {
                        result[j][0] = tp[0];
                        result[j][1] = tp[1];
                        break; // for
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        // vector<vector<int>> result(people.size(), vector<int>(2, NIL));
        sort(people.begin(), people.end(), HeightCmpV2());
        list<vector<int>>  result;

        for(int i = 0; i < people.size(); i++)
        {
            int position = people[i][1]; // 插入到下标为position的位置
            std::list<vector<int>>::iterator it = result.begin();
            while (position--) { // 寻找在插入位置
                it++;
            }
            result.insert(it, people[i]);
        }
        return vector<vector<int>>(result.begin(), result.end());
    }
};

void test(vector<vector<int>> people,  vector<vector<int>> expected)
{
    Solution sol;
    auto result = sol.reconstructQueue(people);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}, {{5,0},{7,0},{5,2},{6,1},{4,4},{7,1}});
    test({{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}}, {{4,0},{5,0},{2,2},{3,2},{1,4},{6,0}});
    return 0;
}

