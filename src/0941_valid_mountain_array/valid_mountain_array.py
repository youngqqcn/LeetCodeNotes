# coding:utf8

from typing import *

class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3 :
            return False

        i = 1
        flagIncrease = False # 上升
        flagDecrease = False # 下降

        while i < len(arr) and arr[i-1] < arr[i]:
            flagIncrease = True
            i += 1

        while i < len(arr) and arr[i-1] > arr[i]:
            flagDecrease = True
            i += 1

        return i == len(arr) and flagIncrease and flagDecrease



