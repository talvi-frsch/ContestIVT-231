package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}

	lMax := make([]int, n)
	rMax := make([]int, n)
	lMax[0] = h[0]
	rMax[n-1] = h[n-1]
	w := 0

	for i := 1; i < n; i++ {
		lMax[i] = max(lMax[i-1], h[i])
	}

	for i := n - 2; i >= 0; i-- {
		rMax[i] = max(rMax[i+1], h[i])
	}

	for i := 0; i < n; i++ {
		w += min(lMax[i], rMax[i]) - h[i]
	}

	fmt.Println(w)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
	return a
	}
	return b
}
