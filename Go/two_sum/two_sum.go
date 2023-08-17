package main

import "fmt"

func main() {
	massive := [...]int{-1, -8, 1, 2}
	val := 0
	fmt.Println(find(massive[:], val))
}

/*
function return indexes of two values from array with sum equal to k
*/
func find(arr []int, k int) []int {
	m := make(map[int]int)

	for i, a := range arr {
		if j, ok := m[k-a]; ok { // если значение k-a уже есть в массиве, значит, arr[j] + arr[i] = k и мы нашли, то что нужно
			return []int{i, j}
		}
		m[a] = i
	}
	return nil
}
