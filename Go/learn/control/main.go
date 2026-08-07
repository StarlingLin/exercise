package main

import (
	"fmt"
	"time"
)

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

	// type-switch
	var r any = 100
	switch v := r.(type) {
	case int:
		fmt.Println("int:", v)
	case string:
		fmt.Println("str:", v)
	default:
		fmt.Println("Unknown")
	}

	// switch 用fallthrough取消break(!!!会直接跳过下一个case的判断)
	switch {
	case false:
		fmt.Println("case1 ok")
		fallthrough
	case true:
		fmt.Println("case2 ok")
		fallthrough
	case false:
		fmt.Println("case3 ok")
		fallthrough
	case true:
		fmt.Println("case4 ok")
		fallthrough
	case false:
		fmt.Println("case5 ok")
		fallthrough
	case true:
		fmt.Println("case6 ok")
		fallthrough
	default:
		fmt.Println("default case.")
	}

	// select - 只用于chan的switch
	// 监听所有case通道，任意case可用时执行，多个可用随机选择
	// 一般没有default来阻塞直到某case可用
	c1 := make(chan string)
	c2 := make(chan string)
	go func() {
		time.Sleep(time.Second)
		c1 <- "one"
	}()
	go func() {
		time.Sleep(time.Second)
		c2 <- "two"
	}()
	for i := 0; i < 2; i++ {
		select {
		case msg1 := <-c1:
			fmt.Println(msg1)
		case msg2 := <-c2:
			fmt.Println(msg2)
		}
	}
	ch1 := make(chan string)
	ch2 := make(chan string)
	go func() {
		for {
			ch1 <- "from1"
			time.Sleep(5 * time.Second)
		}
	}()
	go func() {
		for {
			ch2 <- "from2"
			time.Sleep(4 * time.Second)
		}
	}()
	for {
		select {
		case msg1 := <-ch1:
			fmt.Println(msg1)
		case msg2 := <-ch2:
			fmt.Println(msg2)
		default:
			fmt.Println("nothing.")
			time.Sleep(3 * time.Second)
		}
	}
}
