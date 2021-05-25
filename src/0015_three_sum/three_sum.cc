// Author: yqq
// Date: 2021-05-21 18:10:24
// Description: three nums sum

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> result;
    //     set<vector<int> > resultSet;
    //     std::sort(nums.begin(), nums.end(), [](int a, int b){return a < b;});
    //     for(int i = 0; i < nums.size(); i++)
    //     {
    //         int a = nums[i];
    //         for(int j = i+1; j < nums.size(); j++)
    //         {
    //             int b = nums[j];
    //             for(int k = j+1; k < nums.size(); k++)
    //             {
    //                 int c = nums[k];
    //                 if(0 == nums[i] + nums[j] + nums[k] )
    //                 {
    //                     auto oneResult = vector<int>({a, b, c});
    //                     if(resultSet.find(oneResult) == resultSet.end())
    //                     {
    //                         resultSet.insert(oneResult);
    //                         result.emplace_back(oneResult);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     return result;
    // }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> resultSet;
        std::sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0) continue;

            if (i > 0 && nums[i] == nums[i - 1]) 
            {
                continue;
            }

            int left = i+ 1;
            int right = nums.size() - 1;
            for(;left < right;)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0) 
                {
                    right--;
                }
                else if(sum < 0)
                {
                    left++;
                }
                if (sum == 0)
                {
                    resultSet.insert({nums[left], nums[i], nums[right]});
                    right--; 
                    left++;
                    continue;
                }
            }
        }
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};

void test(vector<int> &nums)
{
    auto vctResult = Solution().threeSum(nums);
    for (auto v : vctResult)
    {
        for (auto item : v)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << "================" << endl;
}

int main()
{

    vector<int> vctNums({-1, 0, 1, 2, -1, -4});
    test(vctNums);
    // // // -4, -1, -1, 0, 1, 2
    vector<int> vctNums2({3, 0, -2, -1, 1, 2});
    test(vctNums2);

    vector<int> vctNums3({1, 2, -2, -1});
    test(vctNums3);

    vector<int> vctNums4({-1,0,1,2,-1,-4,-2,-3,3,0,4});
    test(vctNums4);

    return 0;
}
