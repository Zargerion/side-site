package main

import (
	"encoding/json"
	"fmt"
	"strconv"
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
	fmt.Println(infos.Products)

}

func StringToFloat(s string) (float64, error) {

	f, err := strconv.ParseFloat(s, 64)
	if err != nil {
		fmt.Println(err)
		return 0, err
	}
	return f, nil
}
