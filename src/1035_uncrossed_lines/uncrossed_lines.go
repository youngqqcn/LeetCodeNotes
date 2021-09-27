// author: yqq
// date: 2021-09-27 16:46:12
// descriptions:
package main
import "fmt"


func maxUncrossedLines(A []int, B []int) int {
	m, n := len(A), len(B)
	dp := make([][]int, m+1)
    for i := range dp {
        dp[i] = make([]int, n+1)
    }

	for i := 1; i <= len(A); i++ {
		for j := 1; j <= len(B); j++ {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][n];

}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
    fmt.Println("hello world")
}

