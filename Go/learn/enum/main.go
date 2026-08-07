package main

import "fmt"

//go:generate stringer -type=Singer
type Singer int

const (
	_ Singer = iota
	Miku
	Rin
	Len
	Lucas
	Meiko
	Kaito
)

func main() {
	fmt.Println(Miku, Rin, Len, Lucas, Meiko, Kaito)
}
