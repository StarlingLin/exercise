package main

import "fmt"

func main() {
br:
	for i := 0; i < 5; i++ {
		fmt.Printf("i: %d\n", i)
		for j := 6; j < 9; j++ {
			fmt.Printf("j: %d\n", j)
			break br
		}
	}
}
