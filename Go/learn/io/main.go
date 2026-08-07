package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	//----------
	// OUTPUT
	//----------
	os.Stdout.WriteString("Hello!\n")

	print("Hello!\n") // 一般输出到stderr，建议仅调试使用
	println("Hello!") // 同上

	fmt.Print("Hello!\n") // 任意类型参数，若类型实现fmt.Stringer接口则调用，内部使用了反射因此性能敏感场景不建议
	fmt.Println("Hello!") // 同上

	// 带缓冲，默认4KB缓冲区，大量小文件IO网络IO建议用减少底层write次数
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	writer.WriteString("BufHello!\n")
	fmt.Fprintln(writer, "BufHello!") // 和上一行一样

	fmt.Printf("%s\n", "Hello1!")
	fmt.Printf("%q\n", "Hello2!")
	fmt.Printf("%#b\n", 2<<7-1) // 0b11111111
	fmt.Printf("%#o\n", 2<<7-1) // 0377
	fmt.Printf("%O\n", 2<<7-1)  // 0o377
	fmt.Printf("%x\n", 2<<7-1)  // ff
	fmt.Printf("%#X\n", 2<<7-1) // 0XFF
	type example struct {
		e1 int
		e2 string
	}
	fmt.Printf("%v\n", example{114514, "田所浩二"})  // {114514 田所浩二}
	fmt.Printf("%+v\n", example{114514, "田所浩二"}) // {e1:114514 e2:田所浩二}
	fmt.Printf("%#v\n", example{114514, "田所浩二"}) // main.example{e1:114514, e2:"田所浩二"}
	fmt.Printf("%T\n", example{})                // main.example
	fmt.Printf("%U\n", '码')                      // U+7801
	fmt.Printf("% x\n", "abcdef")                // 61 62 63 64 65 66
}
