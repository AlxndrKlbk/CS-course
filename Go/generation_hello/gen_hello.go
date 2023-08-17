package main

import (
	"fmt"
	"os"
	"time"
)

func main() {
	var date time.Time
	var err error

	if len(os.Args) == 2 {
		date, err = time.Parse("2006-01-02", os.Args[1])
		if err != nil {
			fmt.Println(err)
		}
	} else {
		date = time.Date(2000, 12, 1, 0, 0, 0, 0, time.UTC)
	}

	y := date.Year()
	switch {
	case y >= 1946 && y < 1965:
		fmt.Println("Привет, бумер!")
	case y >= 1965 && y < 1981:
		fmt.Println("Привет, представитель X!")
	case y >= 1981 && y < 1997:
		fmt.Println("Привет, миллениал!")
	case y >= 1997 && y < 2013:
		fmt.Println("Привет, зумер!")
	case y >= 2013:
		fmt.Println("Привет, альфа!")
	default:
		fmt.Println("Здравствуйте!")
	}
}
