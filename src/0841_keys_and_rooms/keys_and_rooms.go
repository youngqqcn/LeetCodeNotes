// author: yqq
// date: 2021-09-18 14:46:04
// descriptions:
package main
import "fmt"

func dfs(key int, rooms [][]int, visited []bool ) {
	if visited[key] {
		return;
	}

	visited[key] = true
	keys := rooms[key]
	for _ , key := range keys {
		// 深度优先搜索遍历
		dfs(key, rooms, visited);
	}
}

func canVisitAllRooms(rooms [][]int) bool {

	visited := make([]bool, len(rooms));
	dfs(0, rooms, visited);

	//检查是否都访问到了
	for i := 0; i < len(visited); i++ {
		if !visited[i] {
			return false;
		}
	}
	return true;
}


func main() {
    fmt.Println("hello world")
}

