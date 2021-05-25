// author: yqq
// date: 2021-05-25 15:16:09
// descriptions: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
package main

import "fmt"



func letterCombinations(digits string) []string {
	var result []string = []string{}
	var combstr []byte = []byte{}
	if len(digits) == 0 {
		return result
	}

	letterMap  := []string{
		"",     // 0
		"",     // 1
		"abc",  // 2
		"def",  // 3
		"ghi",  // 4
		"jkl",  // 5
		"mno",  // 6
		"pqrs", // 7
		"tuv",  // 8
		"wxyz", // 9
	}
	
	// 也可以将 backtracking 作为单独的函数
	type  F func ( []byte,  int,  *[]string,  *[]byte, F ) 
	backtracking := func (digits []byte, index int, allResult *[]string, combstr *[]byte, selfFunc F ) {
		if index == len(digits) {
			*allResult = append(*allResult, string(*combstr))
			return
		}
		idx := digits[index] - '0'
		letters := letterMap[idx]
		for j := 0; j < len(letters); j++ {
			// 处理
			*combstr = append(*combstr, letters[j])
			// 递归
			selfFunc(digits, index+1, allResult, combstr, selfFunc)
			// 回溯
			*combstr = (*combstr)[:len(*combstr)-1]
		}
	}
	backtracking([]byte(digits), 0, &result, &combstr, backtracking)
	return result
}

func test(digits string) {
	result := letterCombinations(digits)
	for _, combination := range result {
		fmt.Printf(combination + " ")
	}
	fmt.Println()
}

func main() {
	test("23")
	// fmt.Println("hello world")
}
