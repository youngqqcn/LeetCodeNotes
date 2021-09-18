// author: yqq
// date: 2021-09-18 16:24:38
// descriptions:
package main
import "fmt"


func getString(s string) string {
	bz := []rune{}
	for _, c := range s {
		if c != '#' {
			bz = append(bz, c); // 模拟入栈
		} else if len(bz) > 0 { // 栈非空才能弹栈
			bz = bz[:len(bz)-1] // 模拟弹栈
		}
	}
	return string(bz)
}

func backspaceCompare(s string, t string) bool {
	return getString(s) == getString(t)
}


func main() {
    fmt.Println("hello world")
}

