package main

import "fmt"

// const部分用法见enum

func main() {
	var num1 int = 1919810
	var num2 float64
	num2 = 0.114514
	name := "Starling"
	x, y := 123, 456 // 短声明，自动推断类型
	// 短声明不能重复用，但是同时短声明至少一个新变量就可以作为赋值通过编译
	// 即:=左边至少有一个新变量，x赋值z声明
	x, z := 1919, 810
	const Pi = 3.1415926535897932384626
	const Name = "Starling"
	fmt.Println(num1, num2, name, x, y, z)
}
