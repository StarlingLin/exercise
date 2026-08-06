package main

import "fmt"

func main() {
	// 整形字面量
	fmt.Println(114514)   // 114514
	fmt.Println(114_514)  // 114514
	fmt.Println(11_4514)  // 114514
	fmt.Println(3_2_5)    // 325
	fmt.Println(0x1b_f52) // 114514
	fmt.Println(0o337522) // 114514
	fmt.Println(0b_0_0_0) // 0
	// 浮点字面量
	fmt.Println(0.)           // 0
	fmt.Println(0114.514)     // 114.514
	fmt.Println(1.e+5)        // 100000.0
	fmt.Println(1.14e-1)      // 0.114
	fmt.Println(.514e3)       // 514.0
	fmt.Println(19_19.)       // 1919.0
	fmt.Println(0.114514e0_6) // 114514.0
	fmt.Println(0x1p-2)       // 0.25 - p为16进制下乘算2的指数 0x1 * 2^(-2)
	fmt.Println(0x2.p10)      // 2048.0
	fmt.Println(0x_3F3Fp-16)  // 0.2470550537109375
	// 复数字面量
	fmt.Println(0i)      // 0+0i
	fmt.Println(114i)    // 0+114i
	fmt.Println(0o162i)  // 0+114i
	fmt.Println(0x72i)   // 0+114i
	fmt.Println(0.i)     // 0+0i
	fmt.Println(1.e+0i)  // 0+1i - 这边1.e+0是一起解析的，最后解析i
	fmt.Println(1e6i)    // 0+1000000i
	fmt.Println(0x1p-2i) // 0+0.25i
	// 字符字面量（UTF-8全支持）
	fmt.Printf("%c", '咕')
	fmt.Printf("%c", '\000') // 无开头为8进制转译
	fmt.Printf("%c", '\377')
	fmt.Printf("%c", '\xff')   // x开头为16进制转译
	fmt.Printf("%c", '\u12e4') // Unicode码点，U+12e4
	fmt.Printf("%c", '\U00101234')
	// 字符串字面量 - 使用双引号或者反引号（反引号禁止转义）
	fmt.Println(`abc`)
	fmt.Println(`\n
\n`) // 这个等于 "\\n\n\\n"，不要这样跨行写
	fmt.Println("\ttest")
	fmt.Println("\u65e5本\U00008a9e")
}
