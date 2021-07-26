// author: yqq
// date: 2021-07-26 15:57:15
// descriptions:  https://leetcode-cn.com/problems/implement-stack-using-queues
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
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 

注意：

你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty 这些操作。
你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 

示例：

输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
 

提示：

1 <= x <= 9
最多调用100 次 push、pop、top 和 empty
每次调用 pop 和 top 都保证栈不为空
 

进阶：你能否实现每种操作的均摊时间复杂度为 O(1) 的栈？
换句话说，执行 n 个操作的总时间复杂度 O(n) ，尽管其中某个操作可能需要比其他操作更长的时间。你可以使用两个以上的队列。

*/


class MyStack {

private:
    queue<int> _m_queue;

public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        _m_queue.push(x);
        for(int i = 0; i < _m_queue.size() - 1; i++)
        {
            _m_queue.push( _m_queue.front() );
            _m_queue.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = _m_queue.front();
        _m_queue.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        return _m_queue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _m_queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

void test()
{
    MyStack* obj = new MyStack();
    obj->push(66);
    int param_3 = obj->top();
    int param_2 = obj->pop();
    if(!obj->empty())
    {
        cout << "FAILED" << endl;
    }
    else
    {
        cout << "PASSED" << endl;
    }

    delete obj;
}

int main()
{
    test();

    return 0;
}

