// author: yqq
// date: 2021-09-16 16:12:04
// descriptions:
package main
import "fmt"

func pivotIndex(nums []int) int {
	sum := 0
	for _, v := range nums {
		sum += v;
	}

	leftSum := 0    // 中心索引左半和
	rightSum := 0   // 中心索引右半和
	for i := 0; i < len(nums); i++ {
		leftSum += nums[i]
		rightSum = sum - leftSum + nums[i]
		if leftSum == rightSum{
			return i
		}
	}
	return -1
}


func main() {
    fmt.Println("hello world")
}

