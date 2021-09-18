#coding:utf8

from typing import *

class Solution:

    def get_string(self, s: str) -> str :
        bz = []
        for i in range(len(s)) :
            c = s[i]
            if c != '#' :
                bz.append(c) # 模拟入栈
            elif len(bz) > 0: # 栈非空才能弹栈
                bz.pop() # 模拟弹栈
        return str(bz)

    def backspaceCompare(self, s: str, t: str) -> bool:
        return self.get_string(s) == self.get_string(t)
        pass

def main():
    sol = Solution()
    print(sol.backspaceCompare("y#fo##f", "y#f#o##f"))
    pass

if __name__ == '__main__':
    main()
