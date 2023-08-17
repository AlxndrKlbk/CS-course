package main

import (
	"fmt"
	"unicode"
)

func main() {
	fmt.Println(isASCII("тест"))
	fmt.Println(isASCII("test"))
}

func isASCII(str string) bool {
	for _, val := range str {
		if val > unicode.MaxASCII {
			return false
		}
	}
	return true
}
