package main

import "fmt"

const (
    one = 2*iota + 1
    three
    five
    seven
    nine
    eleven
)

func main() {
    fmt.Println(one, three, five, seven, nine, eleven)
} 