// Author: yqq
// Date: 2021-05-14 16:50:08
// Description: two sum

// https://leetcode-cn.com/problems/two-sum/
// https://github.com/youngqqcn/leetcode-master/blob/master/problems/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.md

#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_map>
#include <algorithm>
#include <stdlib.h> // malloc
#include <string.h> // memset
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cur = nums[i];
            auto it = m.find(target - cur);
            if (it != m.end())
            {
                return {i, it->second}; // 使用c++11的initialize_list, 可以省去一次拷贝
            }
            m.insert(std::make_pair(cur, i));
        }
        return {};
    }
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// C 语言实现, 用双循环
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *pReturn = (int *)malloc(sizeof(int) * (*returnSize));
                pReturn[0] = i;
                pReturn[1] = j;
                return pReturn;
            }
        }
    }
    return NULL;
}

void testCpp(vector<int> inputs, int target, vector<int> expected)
{
    vector<int> ret = Solution().twoSum(inputs, target);
    std::sort(ret.begin(), ret.end(), [](int a, int b) -> bool
              { return a < b; });
    assert(expected == ret);
}

void testC(int *inputs, int inputsSize, int target, int *expected, int expectedSize)
{
    int returnSize = 0;
    int *result = twoSum(inputs, inputsSize, target, &returnSize);
    if (NULL != result)
    {
        assert(returnSize == expectedSize);
        memcmp(result, expected, expectedSize * sizeof(int));
        free(result);
    }
}

int main()
{
    // 以下初始化vector的方式, 使用了c++11的initialize_list特性,
    // nums = [2,7,11,15], target = 9
    // [0,1]
    {
        int inputs[] = {2, 7, 11, 15};
        int expected[] = {0, 1};
        int target = 9;
        testCpp(vector<int>(inputs, inputs + sizeof(inputs) / sizeof(int)), target, vector<int>(expected, expected + sizeof(expected) / sizeof(int)));
        testC(inputs, sizeof(inputs) / sizeof(int), 9, expected, sizeof(expected) / sizeof(int));
    }

    // nums = [3,2,4], target = 6
    // [1, 2]
    {
        int inputs[] = {3, 2, 4};
        int expected[] = {1, 2};
        int target = 6;
        testCpp(vector<int>(inputs, inputs + sizeof(inputs) / sizeof(int)), target, vector<int>(expected, expected + sizeof(expected) / sizeof(int)));
        testC(inputs, sizeof(inputs) / sizeof(int), target, expected, sizeof(expected) / sizeof(int));
    }

    // nums = [3,3], target = 6
    // [0, 1]
    testCpp(vector<int>({3, 3}), 6, std::vector<int>({0, 1}));
    {
        int inputs[] = {3, 3};
        int expected[] = {0, 1};
        int target = 6;
        testCpp(vector<int>(inputs, inputs + sizeof(inputs) / sizeof(int)), target, vector<int>(expected, expected + sizeof(expected) / sizeof(int)));
        testC(inputs, sizeof(inputs) / sizeof(int), target, expected, sizeof(expected) / sizeof(int));
    }

    // nums = [], target = 0
    // []
    testCpp(vector<int>({}), 0, std::vector<int>({}));
    {
        int inputs[] = {};
        int expected[] = {};
        int target = 0;
        testCpp(vector<int>(inputs, inputs + sizeof(inputs) / sizeof(int)), target, vector<int>(expected, expected + sizeof(expected) / sizeof(int)));
        testC(inputs, sizeof(inputs) / sizeof(int), target, expected, sizeof(expected) / sizeof(int));
    }

    std::cout << "test passed" << std::endl;
    return 0;
}
