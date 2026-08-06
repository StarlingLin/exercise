package main

import (
	"errors"
	"fmt"
)

func add(a, b int) int {
	return a + b
}

func devide(a, b float64) (float64, error) {
	if b == 0 {
		return 0, errors.New("除数为零")
	}
	return a / b, nil
}

func swap(s1, s2 string) (string, string) {
	return s2, s1
}

func main() {
	sum := add(114, 514)
	fmt.Println("114 + 514 =", sum)
	ratio, err := devide(514, 114)
	if err != nil {
		fmt.Println(err)
	} else {
		fmt.Println("514 / 114 =", ratio)
	}
	_, err = devide(1919, 0)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(swap("world", "Hello"))
}
