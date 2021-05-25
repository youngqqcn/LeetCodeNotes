// author: yqq
// date: 2021-05-25 10:10:09
// descriptions: https://leetcode-cn.com/problems/valid-parentheses/
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        map<char, char> m;
        set<char> left;
        m.insert(make_pair('}', '{'));
        m.insert(make_pair(']', '['));
        m.insert(make_pair(')', '('));
        left.insert('[');
        left.insert('{');
        left.insert('(');
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if('}' == ch || ')' == ch || ']' == ch )
            {
                bool flag = false;
                while(!stk.empty())
                {
                    if(m[ch] == stk.top() )
                    {
                        flag = true;
                        stk.pop();
                        break;
                    }
                    // 如果是别的左括号
                    if(left.find(stk.top()) != left.end()) 
                    {
                        return false;
                    }
                    stk.pop();
                }
                if(!flag) return false;
            }
            else
            {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }

    //  bool isValid(string s) {
    //     stack<int> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(') st.push(')');
    //         else if (s[i] == '{') st.push('}');
    //         else if (s[i] == '[') st.push(']');
    //         // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
    //         // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
    //         else if (st.empty() || st.top() != s[i]) return false;
    //         else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
    //     }
    //     // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
    //     return st.empty();
    // }
};

void test(string s, bool expected)
{
    Solution sol;
    if (expected == sol.isValid(s))
    {
        cout << "\"" << s << "\"" << "    PASSED" << endl;
    }
    else
    {
        cout << "\"" << s << "\"" << "    FAILED" << endl;
    }
}

int main()
{
    test("(82)", true);
    test("()[]{}", true);
    test("(]", false);
    test("([)]", false);
    test("{[]}", true);
    test("({[)", false);
    // cout << "hello world" << endl;
    return 0;
}
