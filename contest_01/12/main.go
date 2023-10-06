package main

import "fmt"

func main() {
	var x uint32
	var c uint32
	
    fmt.Scan(&x)
	
    for x > 1 {
		if x % 2 == 0 {
			x = x/2
            c = c + 1
		}else{
        	x = 3*x + 1
        	c = c + 1
        }
	}
	
    fmt.Println(c)
}
