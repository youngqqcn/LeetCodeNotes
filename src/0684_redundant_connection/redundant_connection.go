// author: yqq
// date: 2021-09-03 14:10:14
// descriptions:
package main

import (
	"fmt"
	"reflect"
)


// 全局变量
var (
    n = 1005 // 节点数量3 到 1000
    father = make([]int, 1005)
)

// 并查集初始化
func initialize() {
	for i := 0; i < n; i++ {
		father[i] = i
	}
}

// 并查集里寻根的过程
func find(u int) int {
	if u == father[u] {
		return u
	}
	father[u] = find(father[u])
	return father[u]
}

// 将v->u 这条边加入并查集
func join(u, v int) {
	u = find(u)
	v = find(v)
	if u == v {
		return
	}
	father[v] = u
}

// 判断 u 和 v是否找到同一个根，本题用不上
func same(u, v int) bool {
	u = find(u)
	v = find(v)
	return u == v
}

func findRedundantConnection(edges [][]int) []int {
	initialize()
	for i := 0; i < len(edges); i++ {
		if same(edges[i][0], edges[i][1]) {
			return edges[i]
		} else {
			join(edges[i][0], edges[i][1])
		}
	}
	return []int{}
}

func main() {
	result := findRedundantConnection([][]int{{1, 2}, {1, 3}, {2, 3}})
	if !reflect.DeepEqual(result, []int{2, 3}) {
		fmt.Println("FAILEED")
	} else {
		fmt.Println("PASSED")
	}
}
