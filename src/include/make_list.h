#pragma once

#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* makeList(vector<int> &nums)
{
    ListNode *head = nullptr;
    ListNode *p = nullptr;
    for(int i = 0; i < nums.size(); i++)
    {
        if( nullptr == head) {
            head = new ListNode(nums[i]);
            p = head;
        }else {
            p->next = new ListNode(nums[i]);
            p = p->next;
        }
    }
    return head;
}