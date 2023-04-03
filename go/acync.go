package main

import (
	"fmt"
	"time"
)

func longRunningTask() int {
	time.Sleep(3 * time.Second)
	return int(time.Now().Unix() % 100)
}

func thread() {
	r := longRunningTask()
	fmt.Printf("%d %s\n", r, time.Now().Format(time.RFC1123))
}

func main() {
	go thread()
	a := 0
	for {
		fmt.Printf("%d | %s\n", a, time.Now().Format(time.RFC1123))
		a++
		time.Sleep(1 * time.Second)
	}
}