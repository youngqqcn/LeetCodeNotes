// author: yqq
// date: 2021-05-23 18:49:32
// descriptions:
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution
{
    // set<vector<int>> threeSum(vector<int> &nums, int target)
    set<vector<int>> threeSum(vector<int> &nums, int target)
    {
        set<vector<int>> resultSet;
        for (int i = 0; i < nums.size(); i++)
        {
            // if(nums[i] > target) continue;

            if (i > 0 && nums[i] == nums[i - 1]) 
            {
                continue;
            }

            int left = i+ 1;
            int right = nums.size() - 1;
            for(;left < right;)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > target)
                {
                    right--;
                }
                else if(sum < target)
                {
                    left++;
                }
                if (sum == target)
                {
                    resultSet.insert({0/*占位*/, nums[left], nums[i], nums[right]});
                    right--; 
                    left++;
                    continue;
                }
            }
        }
        return resultSet;
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> resultSet;
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return vector<vector<int>>({});
        for (int i = 0; i < nums.size() - 3; i++)
        {
            vector<int> tmpnums(nums.begin()+i+1, nums.end());
            set<vector<int>> rset = threeSum(tmpnums, target - nums[i]);
            for(auto v: rset)
            {
                v[0] = nums[i];
                // sort(item.begin(), item.end());
                resultSet.insert(v);
            }
        }
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};

int main()
{
    // nums = [1,0,-1,0,-2,2];
    int target = 0;
    Solution sol;
    // auto v = vector<int>({1,0,-1,0,-2,2});
    // auto v = vector<int>({});
    // auto v = vector<int>({1,0,-1,0,-2,2});
    auto v = vector<int>({1,-2,-5,-4,-3,3,3,5});
    target = -11;
    auto result = sol.fourSum(v, target);
    for(auto item: result)
    {
        for(auto n : item)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    cout  << endl;
    return 0;
}
