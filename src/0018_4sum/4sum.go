// author: yqq
// date: 2021-05-23 18:49:32
// descriptions: https://leetcode-cn.com/problems/4sum/
package main

import (
	"fmt"
	"sort"
)

func threeSum(nums []int, target int) [][]int {
	result := [][]int{}
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		// if nums[i] > 0 {
		// 	break
		// }

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		a := nums[i]
		left, right := i+1, len(nums)-1
		for left < right {
			b, c := nums[left], nums[right]
			sum := a + b + c
			if sum < target {
				left++
			} else if sum > target {
				right--
			} else if sum == target {
				result = append(result, []int{0/*占位*/, nums[i], nums[left], nums[right]})

				// 跳过重复的
				for left < right && nums[left] == b {
					left++
				}
				for left < right && nums[right] == c {
					right--
				}
			}
		}
	}

	return result
}

func fourSum(nums []int, target int) [][]int {
	results := [][]int{}
	if len(nums) < 4 {
		return results
	}
	sort.Ints(nums)
	for i := 0; i < len(nums) - 3; i++ {

		// 去重
		if i > 0 && nums[i] == nums[i - 1] {
			continue
		}

		ret := threeSum(nums[i+1:], target - nums[i])
		for _, v := range ret {
			v[0]  = nums[i]
			results = append(results, v)
		}
	}

	return results
}

func test(nums []int, target int) {
	result := fourSum(nums, target)
	fmt.Printf("%v\n", result)
}

func main() {
	test([]int{1, 0, -1, 0, -2, 2}, 0)
	test([]int{2,2,2,2,2}, 8)
	// fmt.Println("hello world")
}
