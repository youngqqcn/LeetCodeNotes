// author: yqq
// date: 2021-09-19 18:21:31
// descriptions:
package main
import "fmt"

func validMountainArray(arr []int) bool {
	if len(arr) < 3 {
		return false
	}

	i := 1
	flagIncrease := false // 上升
	flagDecrease := false // 下降
	
	for ; i < len(arr) && arr[i-1] < arr[i]; i++ {
		flagIncrease = true;
	}

	for ; i < len(arr) && arr[i-1] > arr[i]; i++ {
		flagDecrease = true;
	}

	return i == len(arr) && flagIncrease && flagDecrease;
}


func main() {
    fmt.Println("hello world")
}

