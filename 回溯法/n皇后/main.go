package main

import (
	"fmt"
	"math"
)

var counter int

func isAvailable(arr []int, n int) bool {
	for i := 0; i < n; i++ {
		if arr[i] == arr[n] || n-i == int(math.Abs(float64(arr[n]-arr[i]))) {
			return false
		}
	}
	return true
}

func nQueen(arr []int, k int, n int) {
	if k == n {
		counter++
		return
	}
	for i := 0; i < n; i++ {
		// 放皇后
		arr[k] = i
		if !isAvailable(arr, k) {
			continue
		}
		nQueen(arr, k+1, n)
	}
}
func main() {
	arr := make([]int, 8)
	nQueen(arr, 0, 8)
	fmt.Printf("8皇后的摆放位置共有：%d种方法", counter)
}
