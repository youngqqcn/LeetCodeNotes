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
    test("()", true);
    test("()[]{}", true);
    test("(]", false);
    test("([)]", false);
    test("{[]}", true);
    test("({[)", false);
    // cout << "hello world" << endl;
    return 0;
}
