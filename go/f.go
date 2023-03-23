package main

import (
	"encoding/json"
	"fmt"
)

type Info struct {
	Products []struct {
		Name  string
		Price int
	}
}

func main() {
	x := 10
	fmt.Println(x)
	text := `{"products":[{"name": "sadfsad", "price": 14}, {"name": "fg", "price": 300}, {"name": "a", "price": 123}]}`
	var infos Info
	err := json.Unmarshal([]byte(text), &infos)
	if err != nil {
		fmt.Println(err)
		return
	}
	fmt.Println(infos)
	for
	fmt.Println(infos.Products)

}
