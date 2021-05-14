// Author: yqq
// Date: 2021-05-14 18:27:30
// Description: golang 实现 two sum

// https://leetcode-cn.com/problems/two-sum/

package main

import (
	"fmt"
	"reflect"
)

func twoSum(nums []int, target int) []int {
	set := make(map[int]int, 0)
	for i, n := range nums {
		if idx, ok := set[target-n]; ok {
			return []int{idx, i}
		}
		set[n] = i
	}
	return make([]int, 0)
}

func twoSum2(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{}
}

type MyFunc func([]int, int) []int

func main() {

	funcs := []MyFunc{twoSum, twoSum2}

	for i, function := range funcs {
		{
			// nums = [2,7,11,15], target = 9
			// [0,1]
			result := function([]int{2, 7, 11, 15}, 9)
			expected := []int{0, 1}
			if !reflect.DeepEqual(result, expected) {
				panic("test failed")
			}
		}

		{
			// nums = [3,2,4], target = 6
			// [1, 2]
			result := function([]int{3, 2, 4}, 6)
			expected := []int{1, 2}
			if !reflect.DeepEqual(result, expected) {
				panic("test failed")
			}
		}

		{
			// nums = [], target = 0
			// []
			result := function([]int{}, 0)
			expected := []int{}
			if !reflect.DeepEqual(result, expected) {
				panic("test failed")
			}
		}
		fmt.Printf("test round %d passed\n", i)
	}

}
