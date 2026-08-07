package main

import "fmt"

// iota => /aɪˈoʊtə/ 希腊字母 ι
// 常量计数器

// 每个const块中iota从0开始，每行+1
const (
	a = iota // 0
	b        // 1
	c        // 2
	d        // 3
)

const (
	x = 114
	y = iota // 1 不受上面影响，就是const块中的下标
	z        // 2
	w        // 3
)

// 不用iota时继承上一个，但是iota即使没有被使用也会偷偷自增
const (
	p = iota // 0
	q        // 1
	r = "曼波" // 曼波，此时iota=2
	s        // 曼波，此时iota=3
	t = 114  // 114，此时iota=4
	u        // 114，此时iota=5
	v = iota // 6
)

// 空项继承表达式而不是计算结果，表达式不变，iota本身自增
const (
	i = iota + 1  // 1  iota=0
	j             // 2  iota=1
	k = iota * 2  // 4  iota=2
	l             // 6  iota=3
	m = iota << 3 // 32 iota=4
	n             // 40 iota=5
)

// 还可以用匿名标识符跳过几个项
const (
	e = iota        // 0
	_               // # iota=1
	_               // # iota=2
	f               // 3
	_ = iota * iota // # 16
	g               // 25
)

func main() {
	fmt.Println(a, b, c, d)
	fmt.Println(x, y, z, w)
	fmt.Println(p, q, r, s, t, u, v)
	fmt.Println(i, j, k, l, m, n)
	fmt.Println(e, f, g)
}
