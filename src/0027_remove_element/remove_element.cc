// author: yqq
// date: 2021-05-27 20:49:31
// descriptions:
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    // 暴力查找
    // int removeElement(vector<int> &nums, int val)
    // {
    //     int i = 0;
    //     int removed_count = 0; // 已经移除的元素个数
    //     for (; i + removed_count < nums.size();)
    //     {
    //         if (val == nums[i])
    //         {
    //             for (int j = i; j < nums.size() - removed_count - 1; j++)
    //             {
    //                 nums[j] = nums[j + 1];
    //             }
    //             removed_count++;
    //             continue;
    //         }
    //         i++;
    //     }
    //     return nums.size() - removed_count;
    // }

    // 双指针法
    int removeElement(vector<int> &nums, int val)
    {
        int slow_idx = 0;
        for(int fast_idx = 0; fast_idx < nums.size(); fast_idx++)
        {
            if(val != nums[fast_idx])
            {
                nums[slow_idx] = nums[fast_idx];
                slow_idx++;
            }
        }
        return slow_idx;
    }
};

void test(vector<int> nums, int val, vector<int> expected)
{
    Solution sol;
    int len = sol.removeElement(nums, val);
    if (len != expected.size())
    {
        for (auto item : nums)
        {
            cout << item << ",";
        }
        cout << endl;
        cout << "FAILED" << endl;
        return;
    }


    set<int> newNums(nums.begin(), nums.begin() + len);
    for (int i = 0; i < len; i++)
    {
        if (newNums.find(expected[i]) == newNums.end())
        {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
}

int main()
{
    test({3, 2, 2, 3}, 3, {2, 2});
    test({0, 1, 2, 2, 3, 0, 4, 2}, 2, {0, 1, 4, 0, 3});
    // cout << "hello world" << endl;
    return 0;
}
