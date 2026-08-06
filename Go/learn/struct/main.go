package main

import "fmt"

type Stu struct {
	name string
	age  int
}

// 这个方法对Stu值接收，对s的修改不会影响原值
func (s Stu) printName() string {
	return fmt.Sprintf("name: %s", s.name)
}

// 指针接收可修改原值
func (s *Stu) addAge() {
	s.age++
}

func main() {
	stu1 := Stu{name: "Starling", age: 22}
	fmt.Println(stu1.printName())
	stu1.addAge()
}
