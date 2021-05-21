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
        vector<vector<int>> result;
        set<vector<int>> resultSet;
        std::sort(nums.begin(), nums.end(), [](int a, int b)
                  { return a < b; });

        int left = 0;
        int right = nums.size() - 1;
        int i = left + 1;
        for (; left <= right - 2 && left < i && i < right;)
        {
            for (;; i++)
            {
                int a = nums[left];
                int b = nums[i];
                int c = nums[right];
                if (a + b + c > 0 && i == right - 1)
                {
                    // right 左移
                    right--;
                    continue;
                }
                else if (a + b + c < 0 && i == left + 1)
                {
                    // left 右移
                    left++;
                    continue;
                }
                else
                {
                    // found one
                    vector<int> oneResult({a, b, c});
                    if (resultSet.find(oneResult) == resultSet.end())
                    {
                        resultSet.insert(oneResult);
                        result.push_back(oneResult);
                    }
                }
            }
        }

        return result;
    }
};
}
;

int main()
{

    vector<int> vctNums({-1, 0, 1, 2, -1, -4});
    auto vctResult = Solution().threeSum(vctNums);

    // auto tp1 = std::make_tuple(2, 1, 3);
    // auto tp2 = std::make_tuple(1, 3, 2);
    //
    // auto v1 = vector<int>{2, 1, 3 };
    // auto v2 = vector<int>{1, 3, 2 };

    // std::sort(v1.begin(), v1.end(), [](int x, int y){return x < y;});
    // std::sort(v2.begin(), v2.end(), [](int x, int y){return x < y;});

    // if(v1 == v2)
    // {
    //     cout << "v1 == v2" << endl;
    // }

    for (auto v : vctResult)
    {
        for (auto item : v)
        {
            cout << item << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
