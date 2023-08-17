package main

import "fmt"

func main() {
	dim := 100
	s := make([]int, 0, dim)
	// заполняем слайс числами
	for i := 0; i < dim; i++ {
		s = append(s, i*2)
	}
	// оставляем первые и последние 10 элементов
	s = append(s[:10], s[dim-10:]...)
	dim = len(s)
	// разворачиваем слайс
	for i := range s[:dim/2] {
		s[i], s[dim-i-1] = s[dim-i-1], s[i]
	}
	fmt.Println(s)
}

func main2() {
	input := "The quick brown 狐 jumped over the lazy 犬"
	// Get Unicode code points.
	n := 0
	// создаём слайс рун
	runes := make([]rune, len(input))
	// добавляем руны в слайс
	for _, r := range input {
		runes[n] = r
		n++
	}
	// убираем лишние нулевые руны
	runes = runes[0:n]
	// разворачиваем
	for i := 0; i < n/2; i++ {
		runes[i], runes[n-1-i] = runes[n-1-i], runes[i]
	}
	// преобразуем в строку UTF-8.
	output := string(runes)
	fmt.Println(output)
}
