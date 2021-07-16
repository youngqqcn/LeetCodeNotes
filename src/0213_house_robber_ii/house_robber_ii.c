#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，
这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，
计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 

示例 1：

输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：

输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 3：

输入：nums = [0]
输出：0
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 1000

*/

#define MAX(a, b) ((a > b) ? (a) : (b))
// 参数说明:
//   a: 是给定的正整数组
//   aSize:  是a数组的大小
int doDP(int *a, int aSize)
{
    // 动态规划:
    //
    // dp数组定义:  dp[i] 表示 a[0..i-1] 的最大金额
    // 初始化: dp[0] = 0  dp[1] = a[0]
    // 状态转移方程: dp[i] = max(a[i - 1] + dp[i-2] ,  dp[i-1])
    // 遍历方向: 从左到右

    if(0 == aSize) return 0;
    int dpSize  = aSize +  1;
    int *dp = (int *)calloc(dpSize, sizeof(int));
    dp[0] = 0, dp[1] = a[0];
    for(int i = 2; i < dpSize; i++)
    {
        dp[i] = MAX(a[i - 1] + dp[i - 2] , dp[i-1]);
    }

    int result = dp[dpSize - 1];
    free(dp);
    dp = NULL;
    return result;
}


int robber(int* nums, int numsSize)
{
    if(0 == numsSize) return 0;
    if(1 == numsSize) return nums[0];
    return MAX(doDP(nums, numsSize - 1),  doDP(nums + 1, numsSize - 1));
}

int test(int *nums, int numsSize, int expected)
{
    int result = robber(nums, numsSize);
    if (expected != result)
    {
        printf("error , expected: %d, but got: %d\n", expected, result);
        return 0;
    }

    return 0;
}

typedef struct _TestCase {
    int nums[100];
    int numsSize;
    int expected;
}TestCase;

int main()
{
    TestCase data[] = {
        {nums: {2, 3, 2},  numsSize: 3, expected: 3},
        {nums: {1, 2, 3, 1}, numsSize: 4, expected: 4},
        {nums:{0}, numsSize: 1,expected: 0},
        {nums:{1}, numsSize: 1, expected:1},
        {nums:{1,1,1,2},numsSize:  4,expected: 3},
        {nums:{1,1,3,6,7,10,7,1,8,5,9,1,4,4,3}, numsSize: 15,expected: 41},
        {nums:{2,2,4,3,2,5}, numsSize: 6, expected:10},
        {nums:{94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61, 6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397, 52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72},numsSize:  40,expected: 2926},
        {nums:{226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124},numsSize:  96, expected: 7102},
    };

    for(int i = 0; i < sizeof(data)/ sizeof(TestCase); i++)
    {
        test(data[i].nums, data[i].numsSize, data[i].expected);
    }
    return 0;
}