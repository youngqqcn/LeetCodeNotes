/*
date: 2021-05-22  12:50
author: yqq
descriptions: three sum
*/

package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums) - 2; i++ {
		if nums[i] > 0 {
			break
		}

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		a := nums[i]
		left, right := i+1, len(nums)-1
		for left < right {
			b, c := nums[left] , nums[right]
			sum := a + b + c
			if sum < 0 {
				left++
			} else if sum > 0 {
				right--
			} else if sum == 0 {
				result = append(result, []int{nums[i], nums[left], nums[right]})

				// 跳过重复的
				for left < right && nums[left] == b { left++ }
				for left < right && nums[right] == c { right-- }
			}
		}
	}

	return result
}

func test(nums []int) {
	// sort.Ints(nums)
	// fmt.Printf("%v", nums)
	result := threeSum(nums)
	for _, v := range result {
		for _, item := range v {
			fmt.Printf("%d ", item)
		}
		fmt.Printf("\n")
	}
	fmt.Printf("========\n")
}

func main() {

	test([]int{-1, 0, 1, 2, -1, -4})
	test([]int{3, 0, -2, -1, 1, 2})
	test([]int{1, 2, -2, -1})
	test([]int{-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4})
}
