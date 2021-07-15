#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 

提示：

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/


#define MAX(a, b) ((a > b) ? (a) : (b))
// 参数说明:
//   a: 是给定的正整数组
//   aSize:  是a数组的大小
int robber(int *a, int aSize)
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

int test()
{
    // test case 1
    {
        int nums[] = {1, 2, 3, 1};
        int expected = 4;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test case 2
    {
        int nums[] = {2, 7, 9, 3, 1};
        int expected = 12;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test case 3
    {
        int nums[] = {2, 1, 1, 2};
        int expected = 4;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test case 4
    {
        int nums[] = {2, 4, 8, 9, 9, 3};
        int expected = 19;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test
    {
        int nums[] = {6,6,4,8,4,3,3,10};
        int expected = 27;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

     // test case 5
    {
        int nums[] = {1, 1, 3, 6, 7, 10, 7, 1, 8, 5, 9, 1, 4, 4, 3};
        int expected = 42;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test case 6
    {
        int nums[] = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
        int expected = 3365;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test case 7
    {
        int nums[] = {155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,239,85,146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,242,157,79,133,66,36,165};
        int expected = 4517;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }

    // test case 8
    {
        int nums[] = {226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124};
        int expected = 7102;
        int result = robber(nums, sizeof(nums) /sizeof(nums[0]));
        if (expected != result)
        {
            printf("error , expected: %d, but got: %d\n", expected, result);
            return 0;
        }
    }


    return 0;
}

int main()
{
   return test();
}