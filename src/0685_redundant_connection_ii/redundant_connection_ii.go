// author: yqq
// date: 2021-09-15 10:27:44
// descriptions:
package main

import (
	"fmt"
	"reflect"
)

// 全局变量
var (
	n      = 1005 // 节点数量3 到 1000
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

// getRemoveEdge 在有向图里找到删除的那条边，使其变成树
func getRemoveEdge(edges [][]int) []int {
	initialize()
	for i := 0; i < len(edges); i++ { // 遍历所有的边
		if same(edges[i][0], edges[i][1]) { // 构成有向环了，就是要删除的边
			return edges[i]
		}
		join(edges[i][0], edges[i][1])
	}
	return []int{}
}

// isTreeAfterRemoveEdge 删一条边之后判断是不是树
func isTreeAfterRemoveEdge(edges [][]int, deleteEdge int) bool {
	initialize()
	for i := 0; i < len(edges); i++ {
		if i == deleteEdge {
			continue
		}
		if same(edges[i][0], edges[i][1]) { // 构成有向环了，一定不是树
			return false
		}
		join(edges[i][0], edges[i][1])
	}
	return true
}

func findRedundantDirectedConnection(edges [][]int) []int {
	inDegree := make([]int, len(father))
	for i := 0; i < len(edges); i++ {
		// 统计入度
		inDegree[edges[i][1]] += 1
	}
	// 记录入度为2的边（如果有的话就两条边）
	// 找入度为2的节点所对应的边，注意要倒序，因为优先返回最后出现在二维数组中的答案
	twoDegree := make([]int, 0)
	for i := len(edges) - 1; i >= 0; i-- {
		if inDegree[edges[i][1]] == 2 {
			twoDegree = append(twoDegree, i)
		}
	}

	// 处理图中情况1 和 情况2
	// 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
	if len(twoDegree) > 0 {
		if isTreeAfterRemoveEdge(edges, twoDegree[0]) {
			return edges[twoDegree[0]]
		}
		return edges[twoDegree[1]]
	}

	// 处理图中情况3
 	// 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
	return getRemoveEdge(edges)
}

func main() {
	result := findRedundantDirectedConnection([][]int{{1, 2}, {1, 3}, {2, 3}})
	if !reflect.DeepEqual(result, []int{2, 3}) {
		fmt.Println("FAILEED")
	} else {
		fmt.Println("PASSED")
	}
}
