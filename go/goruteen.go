package main

import "fmt"

func main() {
	ch := make(chan int)
	go func() {
		defer close(ch)
		// Вычисляем значение
		result := 42
		// Отправляем значение в канал
		ch <- result
	}()
	// Получаем значение из канала
	value := <-ch
	// Выводим значение
	fmt.Println(value)
}