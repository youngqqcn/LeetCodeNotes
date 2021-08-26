// author: yqq
// date: 2021-08-26 15:07:23
// descriptions: https://leetcode-cn.com/problems/dota2-senate
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <string.h>
#include <stdlib.h>
using namespace std;


/*
Dota2 的世界里有两个阵营：Radiant(天辉)和 Dire(夜魇)

Dota2 参议院由来自两派的参议员组成。现在参议院希望对一个 Dota2 游戏里的改变作出决定。

他们以一个基于轮为过程的投票进行。在每一轮中，每一位参议员都可以行使两项权利中的一项：

  1.禁止一名参议员的权利：
         参议员可以让另一位参议员在这一轮和随后的几轮中丧失所有的权利。

  2.宣布胜利：
         如果参议员发现有权利投票的参议员都是同一个阵营的，他可以宣布胜利并决定在游戏中的有关变化。

给定一个字符串代表每个参议员的阵营。字母 “R” 和 “D” 分别代表了 Radiant（天辉）和 Dire（夜魇）。然后，如果有 n 个参议员，给定字符串的大小将是 n。

以轮为基础的过程从给定顺序的第一个参议员开始到最后一个参议员结束。这一过程将持续到投票结束。所有失去权利的参议员将在过程中被跳过。

假设每一位参议员都足够聪明，会为自己的政党做出最好的策略，你需要预测哪一方最终会宣布胜利并在 Dota2 游戏中决定改变。输出应该是 Radiant 或 Dire。

 

示例 1：

输入："RD"
输出："Radiant"
解释：第一个参议员来自 Radiant 阵营并且他可以使用第一项权利让第二个参议员失去权力，
因此第二个参议员将被跳过因为他没有任何权利。然后在第二轮的时候，第一个参议员可以宣布胜利，因为他是唯一一个有投票权的人

示例 2：

输入："RDD"
输出："Dire"
解释：
第一轮中,第一个来自 Radiant 阵营的参议员可以使用第一项权利禁止第二个参议员的权利
第二个来自 Dire 阵营的参议员会被跳过因为他的权利被禁止
第三个来自 Dire 阵营的参议员可以使用他的第一项权利禁止第一个参议员的权利
因此在第二轮只剩下第三个参议员拥有投票的权利,于是他可以宣布胜利
 

提示：

给定字符串的长度在 [1, 10,000] 之间.

*/


class Solution
{
public:
    // 贪心法： 总是干掉下一个投票的对手 (循环数组)
    string predictPartyVictory_v1(string senate)
    {
        int n = senate.size();

        int rcount = std::count(senate.begin(), senate.end(), 'R');
        int dcount = senate.size() - rcount;


        while(0 != rcount &&  0 != dcount)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; senate[i] != '0' && j < n + i; j++)
                {
                    int idx = j % n;
                    if(senate[idx] != '0' && senate[i] != senate[idx]) {
                        if(senate[idx] == 'R') rcount--;
                        if(senate[idx] == 'D') dcount--;
                        senate[idx] = '0';
                        break;
                    }
                }
            }
        }

        return ( rcount > 0 ) ? ("Radiant") : ("Dire");
    }

    // 贪心法: 循环队列, 总是干掉下一个投票的对手
    string predictPartyVictory_v2(string senate)
    {
        int n = senate.size();
        queue<int> rQueue, dQueue;

        for(int i = 0; i < n; i++)
        {
            if('R' == senate[i]) {
                rQueue.push(i);
            } else {
                dQueue.push(i);
            }
        }

        while(!rQueue.empty() && !dQueue.empty())
        {
            // 谁靠前，谁活下来
            if(rQueue.front() < dQueue.front() ) {
                // 这里的 + n  很巧妙,  相当于放到下一轮
                rQueue.push( rQueue.front() + n );
            }
            else {
                dQueue.push( dQueue.front() + n );
            }
            rQueue.pop();
            dQueue.pop();
        }

        return (!rQueue.empty() ) ? ("Radiant" ) : ("Dire");
    }

    string predictPartyVictory(string senate)
    {
        // R = true表示本轮循环结束后，字符串里依然有R。D同理
        bool R = true, D = true;
        // 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
        int flag = 0;
        while (R && D) { // 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
            R = false;
            D = false;
            for (int i = 0; i < senate.size(); i++) {
                if (senate[i] == 'R') {
                    if (flag < 0) senate[i] = 0; // 消灭R，R此时为false
                    else R = true; // 如果没被消灭，本轮循环结束有R
                    flag++;
                }
                if (senate[i] == 'D') {
                    if (flag > 0) senate[i] = 0;
                    else D = true;
                    flag--;
                }
            }
        }
        // 循环结束之后，R和D只能有一个为true
        return R == true ? "Radiant" : "Dire";
    }

};

void test(string senate, string expected)
{
    Solution solution;
    string result = solution.predictPartyVictory(senate);
    if(result != expected)
    {
        cout << "FAILED" << endl;
        return;
    }
    cout << "PASSED" << endl;
}

int main()
{
    test("RD", "Radiant");
    test("RDD", "Dire");
    test("RDDR", "Radiant");
    test("DRRDRDRDRDDRDRDR", "Radiant");
    return 0;
}
