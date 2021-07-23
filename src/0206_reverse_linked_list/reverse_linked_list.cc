// author: yqq
// date: 2021-07-23 16:48:13
// descriptions: https://leetcode-cn.com/problems/reverse-linked-list/
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
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]
*/

class Solution {
public:
    // 双指针
    ListNode* reverseList(ListNode* head)
    {
        if(nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *fast = head->next;
        ListNode *slow = head;

        while(true)
        {
            ListNode *tmpFastNext = fast->next;
            fast->next = slow;


            if(slow == head)  {
                slow->next = nullptr;
            }
            slow = fast;
            fast = tmpFastNext;

            if(nullptr == fast) {
                break;
            }
        }
        return slow;
    }
};


void test(vector<int> nums, vector<int> expected)
{
    ListNode *head = makeList(nums);

    Solution sol;
    ListNode *newHead = sol.reverseList(head);
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
    test({1,2,3,4,5}, {5,4,3,2,1});
    test({1,2}, {2,1});
    test({}, {});
    test({1}, {1});

    return 0;
}

