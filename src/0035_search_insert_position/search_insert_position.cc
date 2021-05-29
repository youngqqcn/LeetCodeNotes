// author: yqq
// date: 2021-05-29 12:35:49
// descriptions:https://leetcode-cn.com/problems/search-insert-position/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;

class Solution
{
public:
    // 最简单的查找
    int searchInsert_v1(vector<int> &nums, int target)
    {
        int i = 0;
        for(; i < nums.size(); i++)
        {
            if(nums[i] >= target){
                return i;
            }
        }
        return i;
    }

    int binarySearch(vector<int>&nums, const int target, int beginIdx, int endIdx )
    {
        int index = (beginIdx + endIdx) / 2;
        if(index >= nums.size() ) 
            return index;

        if(index == 0 && target <= nums[index]) return index;

        if(0 < index && nums[index-1] < target && target <= nums[index] ){
            return index;
        }

        if(target > nums[index]){
            return binarySearch(nums, target, index+1, endIdx);
        }else{
            return binarySearch(nums, target, beginIdx, index);
        }
    }


    // 二分查找(递归)
    int searchInsert_v2(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size());
    }


    // 二分查找(迭代)
    int searchInsert(vector<int> &nums, int target)
    {
        
        return 0;
    }


};

void test(vector<int> nums, int target, int expectedIndex)
{
    Solution sol;
    int retIndex = sol.searchInsert(nums, target);
    if (retIndex != expectedIndex)
    {
        cout << "=====>FAILED" << endl;
        return;
    }

    // if(nums != expected)
    // {
    //     cout << "FAILED" << endl;
    //     return ;
    // }
    cout << "PASSED" << endl;
}

int main()
{
    test(vector<int>({1, 3, 5, 6}), 5, 2);
    test(vector<int>({1, 3, 5, 6}), 2, 1);
    test(vector<int>({1, 3, 5, 6}), 7, 4);
    test(vector<int>({1, 3, 5, 6}), 0, 0);
    test(vector<int>({1}), 2, 1);
    // cout << "hello world" << endl;
    return 0;
}
