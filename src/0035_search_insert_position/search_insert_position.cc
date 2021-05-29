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
        int n = nums.size();
        int left = 0;
        int right = n; // 定义target在左闭右开的区间里，[left, right)  target
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在 [middle+1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值的情况，直接返回下标
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前 [0,0)
        // 目标值等于数组中某一个元素 return middle
        // 目标值插入数组中的位置 [left, right) ，return right 即可
        // 目标值在数组所有元素之后的情况 [left, right)，return right 即可
        return right;
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
