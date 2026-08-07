package main

import "fmt"

func main() {
br:
	for i := 1; i < 3; i++ {
		fmt.Printf("i: %d\n", i)
		for j := 0; j < 3; j++ {
			fmt.Printf("j: %d\n", j)
			continue br
		}
	}
}
