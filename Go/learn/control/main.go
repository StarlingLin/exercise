package main

import "fmt"

func main() {
	// if
	rate := 90
	if rate >= 90 {
		fmt.Println("A")
	} else if rate >= 60 {
		fmt.Println("B")
	} else {
		fmt.Println("C")
	}
	// for ~ for in cpp
	for i := 0; i < 10; i++ {
		fmt.Print(i, " ")
	}
	fmt.Println()
	// for ~ while in cpp
	n := 5
	for n > 0 {
		fmt.Println(n)
		n--
	}
	// for ~ range for in cpp
	singers := []string{"miku", "rin", "len", "lucas", "meiko", "kaito"}
	for index, singer := range singers {
		fmt.Printf("%03d - %s\n", index+1, singer)
	}
	// switch 不用break，默认全break
	state := "RUN"
	switch state {
	case "RUN":
		fmt.Println("Running.")
	case "STOP":
		fmt.Println("Stopping.")
	default:
		fmt.Println("UNKNOWN")
	}
}
