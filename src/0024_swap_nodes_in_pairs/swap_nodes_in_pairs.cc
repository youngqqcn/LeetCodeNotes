// author: yqq
// date: 2021-05-25 11:55:09
// descriptions: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
#include <iostream>
#include <vector>
#include <memory>
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
    // ~ListNode(){cout << "delete-------" << endl;}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // 增加了一个虚拟头节点, 简化操作
        auto headNode = make_shared<ListNode>(0);
        ListNode *ret;
        headNode->next = head;

        // 循环终止条件要注意
        for(ListNode *cur = headNode.get(); cur->next != nullptr && cur->next->next != nullptr ;  )
        {
            ListNode *node1 = cur->next;
            ListNode *node2 = cur->next->next;
            ListNode *node3 = cur->next->next->next;

            cur->next = node2; 
            cur->next->next = node1;
            cur->next->next->next = node3;

            cur = cur->next->next;
        }
        ret = headNode->next;
        return ret;
    }
};

void test(ListNode *list, vector<int> expected)
{
    Solution sol;
    ListNode *result = sol.swapPairs(list);

    int i = 0;
    for (ListNode *p = result; p != nullptr; p = p->next, i++)
    {
        if (p->val != expected[i])
        {
            cout << "FAILED" << endl;
            return;
        }
    }
    cout << "PASSED" << endl;
}

int main()
{
    ListNode node4(4, nullptr);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);

    test(&node1, {2, 1, 4, 3});
    cout << "hello world" << endl;
    return 0;
}
