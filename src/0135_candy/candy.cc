// author: yqq
// date: 2021-06-27 15:42:19
// descriptions: https://leetcode-cn.com/problems/candy/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
using namespace std;

/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。

那么这样下来，老师至少需要准备多少颗糖果呢？

 

示例 1：

输入：[1,0,2]
输出：5
解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：[1,2,2]
输出：4
解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

*/

class Solution
{
public:
    int set(vector<int> &dp, int i, int value)
    {
        // if (INT32_MIN != dp[i])
        // {
        //     dp[i] = min(dp[i], value);
        // }
        // else
        // {
            dp[i] = value;
        // }
        return dp[i];
    }
    int dpFunc(vector<int> &ratings, int i, vector<int> &dp)
    {
        if (dp[i] != INT32_MIN)
            return dp[i];

        // 递归终止
        if (ratings[i] == 0)
        {
            dp[i] = 1;
            return 1;
        }

        // 第一个
        if (i == 0 && ratings.size() >= 2 && ratings[i] <= ratings[i + 1])
        {
            dp[i] = 1;
            return 1;
        }

        if (i == 0 && i + 1 < ratings.size() && ratings[i] > ratings[i + 1])
        {
            int ret = dpFunc(ratings, i + 1, dp) + 1;
            return set(dp, i, ret);
            ;
        }

        // 最后一个
        if (i + 1 == ratings.size() && i >= 1 && ratings[i - 1] >= ratings[i])
        {
            dp[i] = 1;
            return 1;
        }

        if (i + 1 == ratings.size() && i >= 1 && ratings[i - 1] < ratings[i])
        {
            // cout << "llllllllllllllllllllll" << endl;
            if (INT32_MIN != dp[i - 1])
            {
                int ret = dp[i - 1] + 1;
                return set(dp, i, ret);
            }
            else
            {
                // 从左边递归过来的
                int ret = 2;
                return set(dp, i, ret);
            }
        }

        /*

               \__/

        */
        if (i >= 1 && ratings[i - 1] >= ratings[i] && i + 1 < ratings.size() && ratings[i] <= ratings[i + 1])
        {
            dp[i] = 1;
            return 1;
        }

        /*
             __ __ __

        */
        if (i >= 1 && ratings[i - 1] == ratings[i] && i + 1 < ratings.size() && ratings[i] == ratings[i + 1])
        {
            dp[i] = 1;
            return 1;
        }

        /*
                __/
               /
        */
        if (i >= 1 && ratings[i - 1] < ratings[i] && i + 1 < ratings.size() && ratings[i] < ratings[i + 1])
        {

            int left = -1, right = -1;
            left = dp[i - 1] + 1;
            int ret = left;
            return set(dp, i, ret);
        }

        /*
              __
             /  \
        */
        if (i >= 1 && ratings[i - 1] < ratings[i] && i + 1 < ratings.size() && ratings[i] > ratings[i + 1])
        {

            int left = -1, right = -1;
            if (INT32_MIN != dp[i - 1])
            {
                left = dp[i - 1] + 1;
                right = dpFunc(ratings, i + 1, dp) + 1;
                int ret = max(left, right);
                return set(dp, i, ret);
            }
            else
            {
                // 是从左边递归过来的, 此时不能向左递归, 否则, 就无限递归了
                right = dpFunc(ratings, i + 1, dp) + 1;
                int ret = right;
                return set(dp, i, ret);
            }
        }

        /*
              __ __
             /
        */
        if (i >= 1 && ratings[i - 1] < ratings[i] && i + 1 < ratings.size() && ratings[i] == ratings[i + 1])
        {

            int left = -1, right = -1;
            left = dp[i - 1] + 1;
            int ret = left;
            return set(dp, i, ret);
        }

        /*
            __ __
                  \
        */
        if (i >= 1 && ratings[i - 1] == ratings[i] && i + 1 < ratings.size() && ratings[i] > ratings[i + 1])
        {

            int left = -1, right = -1;
            // 是从左边递归过来的, 此时不能向左递归, 否则, 就无限递归了
            right = dpFunc(ratings, i + 1, dp) + 1;
            int ret = right;
            return set(dp, i, ret);
        }

        /*
             \__
                \
        */
        if (i >= 1 && ratings[i - 1] > ratings[i] && i + 1 < ratings.size() && ratings[i] > ratings[i + 1])
        {
            int left = -1, right = -1;
            right = dpFunc(ratings, i + 1, dp) + 1;
            int ret = right;
            return set(dp, i, ret);
        }

        cout << "=================>"  << "  &&&&&&&&&&&&   " << i << endl;
        return 0;
    }

    void check(vector<int> &dp, vector<int> &ratings)
    {
        for (int i = 1; i < dp.size() - 1; i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                if (!(dp[i - 1] < dp[i]))
                {
                    cout << "check------------>" << i << endl;
                    return;
                }
            }

            if (ratings[i] > ratings[i + 1])
            {
                if (!(dp[i] > dp[i + 1]))
                {
                    cout << "check------------>" << i << endl;
                    return;
                }
            }
        }
        // cout << "check ok" << endl;
    }

    int candy_v1(vector<int> &ratings)
    {
        int sum = 0;
        vector<int> dp(ratings.size(), INT32_MIN);
        for (int i = 0; i < dp.size(); i++)
        {
            if (INT32_MIN != dp[i]) {
                sum += dp[i];
                continue;
            }
            dp[i] = dpFunc(ratings, i, dp);
            sum += dp[i];
        }

        // check(dp, ratings);
        return sum;
    }

    // 使用贪心算法, 两次遍历
    // 非常妙: https://leetcode-cn.com/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/
    int candy(vector<int> &ratings)
    {
        vector<int> cd(ratings.size(),  1);
        for(int i = 1; i < cd.size(); i++)
        {
            if(ratings[i - 1] < ratings[i]) {
                cd[i] =  cd[i - 1] +  1;
            }
        }

        for(int i = cd.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1]) {
                cd[i] = max(cd[i], cd[i + 1] + 1);
            }
        }

        int sum = 0;
        for_each(cd.begin(), cd.end(), [&sum](int n){ sum += n;});
        return sum;
    }

};

void test(vector<int> ratings, int expected)
{
    Solution sol;
    auto result = sol.candy(ratings);
    if (result != expected)
    {
        cout << "FAILED"
             << " expected " << expected << " got " << result << endl;
        return;
    }
    cout << "PASSED" << endl;
    return;
}

vector<int> readTestData(string filename)
{
    vector<int> ratings;
    ifstream testData(filename, ios::binary);
    string line;
    getline(testData, line);
    stringstream ss(line);
    while (getline(ss, line, ','))
    {
        ratings.push_back(atoi(line.c_str()));
    }
    return std::move(ratings);
}

int main()
{
    test({1, 0, 2}, 5);                 // 2 1  2
    test({1, 2, 2}, 4);                 // 1 2 1
    test({1, 3, 2, 2, 1}, 7);           // 1 2 1 2 1
    test({1, 2, 87, 87, 87, 2, 1}, 13); // 1 2 3 1 3 2 1
    test({29, 51, 87, 87, 72, 12}, 12); // 1 2 3 3 2 1
    test({1, 3, 4, 5, 2}, 11);          // 1 2 3 4 1
    test({1, 2, 4, 4, 4, 3}, 10);       // 1 2 3 1 2 1
    test({1, 2, 3, 5, 4, 3, 2, 1, 4, 3, 2, 1, 3, 2, 1, 1, 2, 3, 4}, 47);
    test({370, 28, 37, 15, 379, 458, 342, 346, 328, 257, 81, 400, 426, 461, 349, 362, 315, 410, 427, 458, 264, 322, 326, 350, 369, 383, 184, 343, 402, 274, 184, 124, 154, 73, 491, 33, 31, 333, 379, 212, 91, 313, 112, 369, 274, 461, 83, 441, 223, 362, 399, 339, 185, 77, 189, 406, 312, 373, 249, 66, 147, 433, 191, 153, 358, 182, 187, 242, 368, 418, 454, 311, 231, 418, 180, 358, 379, 115, 151, 454, 478, 403, 293, 163, 480, 482, 69, 145, 207, 318, 63, 207, 103, 254, 360, 313, 289, 399, 55, 9, 318, 361, 320, 401, 279, 352, 111, 10, 319, 263, 464, 297, 18, 109, 460, 350, 91, 381, 495, 151, 51, 59, 358, 6, 165, 218, 320, 306, 118, 375, 315, 288, 89, 487, 41, 368, 191, 5, 379, 11, 120, 195, 308, 138, 305, 121, 488, 248, 2, 336, 399, 406, 395, 257, 412, 412, 328, 232, 71, 446, 460, 238, 86, 49, 226, 127, 417, 269, 132, 148, 280, 104, 344, 441, 242, 1, 414, 231, 101, 416, 419, 1, 174, 314, 110, 87, 78, 438, 319, 149, 236, 279, 388, 322, 328, 466, 302, 98, 235, 286, 246, 368, 391, 442, 161, 133, 295, 75, 216, 397, 343, 135, 250, 18, 301, 360, 105, 232, 299, 424, 381, 35, 56, 121, 210, 384, 439, 12, 482, 175, 298, 81, 395, 41, 23, 408, 175, 171, 483, 243, 68, 178, 231, 318, 48, 32, 178, 153, 116, 329, 430, 498, 217, 338, 471, 279, 222, 411, 291, 57, 438, 441, 490, 185, 483, 365, 93, 10, 36, 428, 105, 104, 106, 336, 274, 155, 221, 305, 160, 337, 134, 442, 335, 203, 280, 159, 482, 355, 70, 125, 412, 360, 67, 254, 45, 402, 119, 138, 412, 156, 66, 17, 112, 24, 206, 387, 179, 427, 192, 192, 264, 178, 134, 452, 382, 415, 111, 216, 270, 33, 342, 34, 393, 261, 288, 290, 163, 407, 428, 427, 63, 346, 444, 176, 370, 2, 415, 402, 429, 107, 94, 194, 285, 80, 146, 19, 495, 109, 236, 117, 494, 78, 151, 387, 191, 439, 29, 354, 199, 457, 281, 114, 155, 77, 290, 25, 80, 57, 279, 361, 164, 225, 55, 302, 306, 53, 321, 153, 14, 57, 271, 8, 487, 422, 247, 178, 214, 276, 384, 413, 233, 17, 27, 240, 95, 170, 118, 27, 227, 397, 388, 244, 475, 296, 46, 281, 201, 367, 434, 216, 277, 57, 224, 264, 332, 472, 295, 398, 248, 179, 311, 334, 197, 190, 74, 144, 212, 192, 23, 292, 442, 263, 388, 417, 411, 434, 50, 113, 153, 336, 329, 430, 394, 53, 47, 226, 377, 194, 124, 126, 225, 287, 312, 274, 329, 238, 418, 394, 283, 293, 186, 225, 409, 426, 494, 320, 360, 44, 433, 365, 380, 262, 148, 126, 316, 47, 204, 45, 241, 180, 23, 466, 467, 335, 241, 149, 426, 11, 43, 209, 157, 81, 286, 66, 7, 280, 386, 219, 176, 320}, 1050);

    test(readTestData("test.data"), 20474);
}

//  r[i] == 0  ===> d[i] = 1
//  r[i]  i == size   r[i] == r[i-1]  ===> dp[i] = 1
//  i == 0   r[i] < r[i+1]   ==> dp[i] = 1   i+1 != size-1 ==> dp[i+1] = 2
//  r[i-1] == r[i] == r[i+1]  ==> dp[i] = 1
