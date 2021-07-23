// author: yqq
// date: 2021-07-23 16:09:50
// descriptions: https://leetcode-cn.com/problems/remove-linked-list-elements
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


#include "../include/make_list.h"


/*
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。


示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
示例 2：

输入：head = [], val = 1
输出：[]
示例 3：

输入：head = [7,7,7,7], val = 7
输出：[]
 

提示：

列表中的节点数目在范围 [0, 104] 内
1 <= Node.val <= 50
0 <= val <= 50

*/


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        if(nullptr == head) return nullptr;

        // 一个辅助头指针, 方便处理头节点
        ListNode *tmpHead = new ListNode();
        tmpHead->next = head;
        ListNode *p = tmpHead;

        for( ;nullptr != p && nullptr != p->next ; )
        {
            if(p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }

        return tmpHead->next;
    }
};


void test(vector<int> nums, int delVal, vector<int> expected)
{
    ListNode *head = makeList(nums);

    Solution sol;
    ListNode *newHead = sol.removeElements(head, delVal);
    ListNode *p = newHead;
    for(int i = 0; i < expected.size(); i++)
    {
        if(p != nullptr && p->val != expected[i])
        {
            cout << "FAILED 1" << endl;
            return;
        }

        p = p->next;
    }

    if(p != nullptr)
    {
        cout << "FAILED 2" << endl;
        return;
    }

    cout << "PASSED" << endl;
}

int main()
{
    test({1,2,6,3,4,5,6}, 6,  {1,2,3,4,5});
    test({}, 1, {});
    test({7,7,7,7}, 7, {});

    return 0;
}

