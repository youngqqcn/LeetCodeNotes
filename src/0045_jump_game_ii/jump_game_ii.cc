// author: yqq
// date: 2021-06-02 17:39:18
// descriptions: https://leetcode-cn.com/problems/jump-game-ii/
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
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1){
            return 0;
        }

        int slowRange = nums[0];
        int maxRange  = slowRange;
        int steps = 1;
        for (int i = 0; i < nums.size() -1 ; i++)
        {
            maxRange = max(nums[i] + i, maxRange);
            if ( i >= slowRange )
            {
                steps++;
                slowRange = maxRange; 
            }
             if(maxRange >= nums.size() - 1){
                if( slowRange < maxRange){
                    steps++;
                }
                break;
            }
        }
        return steps;
    }

    // 
    int jump_v2(vector<int>& nums) {
        int curDistance = 0;    // 当前覆盖的最远距离下标
        int ans = 0;            // 记录走的最大步数
        int nextDistance = 0;   // 下一步覆盖的最远距离下标
        for (int i = 0; i < nums.size() - 1; i++) { // 注意这里是小于nums.size() - 1，这是关键所在
            nextDistance = max(nums[i] + i, nextDistance); // 更新下一步覆盖的最远距离下标
            if (i == curDistance) {                 // 遇到当前覆盖的最远距离下标
                curDistance = nextDistance;         // 更新当前覆盖的最远距离下标
                ans++;
            }
        }
        return ans;
    }
};

void test(vector<int> nums, int expected)
{
    Solution sol;
    int result = sol.jump(nums);
    if (result != expected)
    {
        cout << "FAILED" << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    test({2, 3, 1, 1, 4}, 2);
    test({1, 2, 1, 1, 1}, 3);
    test({7, 0, 9, 6, 9, 6, 1, 7, 9, 0, 1, 2, 9, 0, 3}, 2);
    test({1,2}, 1);
    test({1,1,1,1,1}, 4); // TODO: FIXME
    cout << "hello world" << endl;
    return 0;
}
