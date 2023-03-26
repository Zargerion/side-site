package main

import (
	"fmt"
	"time"
)

func main() {
	t := time.Now().UTC()
	fmt.Println(t.Format("15:04:05"))
	fmt.Println(t.Format("20060102150405"))
	t1 := time.Now().UTC()
	time.Sleep(2 * time.Second)
	t2 := time.Now().UTC()
	duration := t2.Sub(t1).Milliseconds()
	fmt.Println(duration)
}
