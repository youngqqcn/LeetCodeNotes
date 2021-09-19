// author: yqq
// date: 2021-09-19 10:28:43
// descriptions:
package main
import "fmt"

// 方法一
func sortArrayByParityII(nums []int) []int {
	// 分别存放 nums 中的奇数、偶数
	even, odd := []int{}, []int{}
	for i := 0; i < len(nums); i++ {
		if (nums[i] % 2 == 0) {
			even = append(even, nums[i])
		} else {
			odd = append(odd, nums[i])
		}
	}

	// 把奇偶数组重新存回 nums
	result := make([]int, len(nums))
	index := 0
	for i := 0; i < len(even); i++ {
		result[index] = even[i]; index++;
		result[index] = odd[i]; index++;
	}
	return result;
}


func main() {
    fmt.Println("hello world")
}

