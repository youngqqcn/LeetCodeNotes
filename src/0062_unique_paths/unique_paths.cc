// author: yqq
// date: 2021-06-11 21:29:26
// descriptions:
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory>
using namespace std;


class Solution {
public:
    // 深度优先
    int DFS(int row, int col, int m, int n)
    {
        if(row >= m || col >= n)
            return 0;
        if(row == m-1 && col == n-1)
            return 1;

        // 向下 + 向右
        return DFS(row+1, col, m, n) + DFS(row, col+1, m, n);
    }



    int uniquePaths(int m, int n)
    {
        return DFS(0, 0, m, n);
    }
};


void test(int m, int n, int expected)
{
    Solution sol;
    int result = sol.uniquePaths(m, n);
    cout << "result:" << result << endl;
    if(result != expected){
        cout << "FAILED" << endl;
    }else {
        cout << "PASSED" << endl;
    }
}


int main()
{
    test(3, 7, 28);
    test(3, 2, 3);
    test(2, 2, 2);
    test(7, 3, 28);
    test(3, 3, 6);

    // cout << "hello world" << endl;
    return 0;
}

