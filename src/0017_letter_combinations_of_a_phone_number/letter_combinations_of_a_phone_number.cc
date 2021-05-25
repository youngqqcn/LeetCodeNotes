// author: yqq
// date: 2021-05-23 10:34:23
// descriptions: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    const string letterMap[10] = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };
    string str;
    vector<string> result;
public:
   
    void backtracking(const string &digits, int index)
    {
        // 递归终止条件
        if (index == digits.length())
        {
            result.push_back(str);
            return;
        }

        int idx = digits[index] - '0';
        string letters = letterMap[idx];
        for (int j = 0; j < letters.length(); j++)
        {
            // 处理
            str.push_back(letters[j]);

            // 递归
            backtracking(digits, index + 1);

            // 回溯
            str.pop_back();
        }
    }

    // // 迭代方式
    // void backtracking(const string &digits, int index)
    // {
        
    // }

    vector<string> letterCombinations(string digits)
    {
        str.clear();
        result.clear();
        if(0 == digits.size()) 
            return result;

        backtracking(digits, 0);
        return result;
    }
};

void test(string digist)
{
    Solution s;
    vector<string> result = s.letterCombinations(digist);
    for (auto item : result)
    {
        cout << item << "  ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    test("23");
    std::cout << std::endl;
    return 0;
}