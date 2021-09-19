// author: yqq
// date: 2021-09-19 11:02:35
// descriptions:
package main
import "fmt"


func isLongPressedName(name string, typed string) bool {
	if(name[0] != typed[0] || len(name) > len(typed)) {
		return false;
	}

	idx := 0 // name的索引
	var last byte  // 上个匹配字符
	for i := 0; i < len(typed); i++ {
		if idx < len(name) && name[idx] == typed[i] {
			last = name[idx]
			idx++
		} else if last == typed[i] {
			continue
		} else  {
			return false
		}
	}
	return idx == len(name)
}


func main() {
	fmt.Printf("%v\n", isLongPressedName("alex", "aaleex"))
	fmt.Printf("%v\n", isLongPressedName("vtkgn", "vttkgnn"))
}

