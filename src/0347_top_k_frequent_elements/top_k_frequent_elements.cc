// author: yqq
// date: 2021-07-30 10:50:26
// descriptions: https://leetcode-cn.com/problems/top-k-frequent-elements
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
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

1 <= nums.length <= 10^5
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

*/

class Solution {
private:
    struct CmpByValue {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
        {
            // 降序
            return p1.second > p2.second;
        }
    };

    // struct mycomparison {
    //     bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
    //     {
    //         return p1.second > p2.second;
    //     }
    // };

public:
    map<int, int> counts;
    vector<int> topKFrequent_v1(vector<int>& nums, int k)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            counts[nums[i]] += 1;
        }
        typedef pair<int, int> PAIR;
        vector<PAIR> result(counts.begin(), counts.end() );
        sort(result.begin(), result.end(), CmpByValue());

        vector<int> ret;
        for(int i = 0; i < k && i < nums.size(); i++)
        {
            ret.push_back(result[i].first);
        }

        return ret;
    }


    // 优先级队列, 用的妙啊!
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // 要统计元素出现频率
        unordered_map<int, int> map; // map<nums[i],对应出现的次数>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // 对频率排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, CmpByValue> pri_que;

        // 用固定大小为k的小顶堆，扫面所有频率的数值
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒叙来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }

};


void test(vector<int> nums, int k, vector<int> expected)
{
    Solution sol;
    auto result = sol.topKFrequent(nums, k);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({1,1,1,2,2,3}, 2, {1, 2});
    test({1}, 1, {1} );
    return 0;
}

