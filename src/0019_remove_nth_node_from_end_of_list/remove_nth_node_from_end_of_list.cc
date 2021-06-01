// author: yqq
// date: 2021-05-24 19:33:09
// descriptions: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* retHead = head;
        ListNode* p1 = head,  *p2 = head; 
        int i = 0;
        for(; i < n && p1->next != nullptr; i++)
        {
            p1 = p1->next;
        }
        p1 = p1->next;

        // 删除head本身
        if(p1 == nullptr && i == n-1) 
        {
            return head->next;
        }

        for(;p1 != nullptr;)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        p2->next = p2->next->next;
        return retHead;
    }
};

int main()
{
    // [1,2,3,4,5],
    // [1]
    // [1,2]
    // ListNode node1(1, nullptr);

    // ListNode node2(2, nullptr);
    // ListNode node1(1, &node2);

    // [1,2,3]
    // ListNode node3(3, nullptr );
    // ListNode node2(2, &node3);
    // ListNode node1(1, &node2);
    
    ListNode node5(5, nullptr );
    ListNode node4(4, &node5);
    ListNode node3(3, &node4 );
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);

    ListNode *header = &node1;
    Solution sol;
    // ListNode* head = sol.removeNthFromEnd(header, 2);
    ListNode* head = sol.removeNthFromEnd(header, 2);

    for(ListNode* p = head; p != nullptr; p = p->next)
    {
        cout << p->val << ",";
    }
    cout << endl;

    // cout << "hello world" << endl;
    return 0;
}
