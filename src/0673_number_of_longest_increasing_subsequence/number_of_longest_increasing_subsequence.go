// author: yqq
// date: 2021-08-27 15:33:07
// descriptions:
package main
import "fmt"

func findNumberOfLIS(nums []int) int {
	size := len(nums)
	if size <= 1  {
		return size
	}

	dp := make([]int, size);
	for i := range dp {
		dp[i] = 1
	}
	count := make([]int, size);
	for i := range count {
		count[i] = 1
	}


	maxCount := 0
	for i := 1; i < size; i++ {
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				if dp[j] + 1 > dp[i] {
					dp[i] = dp[j] + 1
					count[i] = count[j]
				} else if dp[j] + 1 == dp[i] {
					count[i] += count[j]
				}
			}
			if dp[i] > maxCount {
				maxCount = dp[i]
			}
		}
	}

	result := 0
	for i := 0; i < size; i++ {
		if maxCount == dp[i] {
			result += count[i]
		}
	}
	return result
}


func main() {
	fmt.Printf("%v\n", findNumberOfLIS([]int{1,3,5,4,7}));
}

