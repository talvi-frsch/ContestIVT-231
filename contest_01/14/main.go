package main

import "fmt"

func main() {
	var rows, cols int
	fmt.Scanln(&rows,&cols)

	fmt.Printf("%5s","|")
	for i := 1; i <= cols; i++ {
		fmt.Printf("%4d", i)
	}
	fmt.Println()
	fmt.Print("   --")
	for i := 0; i < cols; i++ {
		fmt.Print("----")
	}
	fmt.Println()
	for i := 1; i <= rows; i++ {
		fmt.Printf("%4d", i)
		fmt.Printf("%s", "|")
		for j := 1; j <= cols; j++ {
			fmt.Printf("%4d", i*j)
		}
		fmt.Println()
	}
}
