// author: yqq
// date: 2021-08-26 15:07:23
// descriptions:
package main
import "fmt"


func predictPartyVictory(senateStr string) string {
	// R = true表示本轮循环结束后，字符串里依然有R。D同理
	R, D := true, true
	// 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
	flag := 0

	senate := []byte(senateStr)
	for R && D { // 一旦R或者D为false，就结束循环，说明本轮结束后只剩下R或者D了
		R = false
		D = false
		for i := 0; i < len(senate); i++ {
			if senate[i] == 'R' {
				if flag < 0  {
					 senate[i] = 0  // 消灭R，R此时为false
				} else {
					R = true // 如果没被消灭，本轮循环结束有R
				}
				flag++;
			}
			if (senate[i] == 'D') {
				if flag > 0 {
					senate[i] = 0
				} else  {
					D = true
				}
				flag--
			}
		}
	}
	// 循环结束之后，R和D只能有一个为true
	if R {
		return "Radiant"
	}
	return "Dire";
}

func main() {
	if "Radiant" == predictPartyVictory("DRRDRDRDRDDRDRDR") {
		fmt.Println("PASSED")
	}else {
		fmt.Println("FAILED")
	}
}

