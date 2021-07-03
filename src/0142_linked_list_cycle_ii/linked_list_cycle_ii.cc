// author: yqq
// date: 2021-07-03 10:40:51
// descriptions:  https://leetcode-cn.com/problems/linked-list-cycle-ii
#include <iostream>
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
using namespace std;

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
如果 pos 是 -1，则在该链表中没有环。
注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：
   你是否可以使用 O(1) 空间解决此题？

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。


提示：

链表中节点的数目范围在范围 [0, 10^4] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引

*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 思路:
//     可以用 set保存已经遍历过的节点 , 如果某个节点的next是在set中,
//     那么次next所指向的节点就是入环第一个节点

class Solution
{
public:
    ListNode *detectCycle_v1(ListNode *head)
    {
        unordered_set<ListNode *> nodes;
        for (ListNode *p = head; p != NULL; p = p->next)
        {
            if (nodes.find(p) != nodes.end())
            {
                return p;
            }
            nodes.insert(p);
        }
        return NULL;
    }

    // 你是否可以使用 O(1) 空间解决此题？
    // https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
    ListNode *detectCycle(ListNode *head)
    {
        if(nullptr == head) return head;

        ListNode *fast = head, *slow = head;
        ListNode *ptr = nullptr;
        while (1)
        {
            if (fast->next == nullptr) return nullptr;
            if (fast->next->next == nullptr) return nullptr;
            if (slow->next == nullptr) return nullptr;

            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow )
            {
                ptr = head;
                while(1)
                {
                    if(ptr == slow) return ptr;
                    ptr = ptr->next;
                    slow = slow->next;
                }
            }
        }
        return NULL;
    }
};

ListNode *makeList(vector<int> values, int pos)
{
    ListNode *header = nullptr;
    ListNode *tail = header;
    ListNode *cycleHeader = nullptr;
    int ipos = 0;
    for (auto item : values)
    {
        if (nullptr == tail)
        {
            header = new ListNode(item);
            tail = header;
        }
        else
        {
            tail->next = new ListNode(item);
            tail = tail->next;
        }
        if (pos == ipos)
        {
            cycleHeader = tail;
        }
        ipos++;
    }
    tail->next = cycleHeader;
    return header;
}

void test(ListNode *head, ListNode *expected)
{
    Solution sol;
    auto result = sol.detectCycle(head);
    if (result != expected)
    {
        cout << "FAILED" << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }
}

int main()
{
    ListNode *header = makeList({3, 2, 0, -4}, 1);
    ListNode *expected = header->next;
    test(header, expected);
    cout << "hello world" << endl;
    return 0;
}
