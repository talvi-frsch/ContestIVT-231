package main
import "fmt"

func main() {
	var n, f int
    fmt.Scan(&n)
    var array [] int
    for i := 0; i < n; i++ {
    	fmt.Scan(&f)
        array = append(array, f)
    }
    fmt.Print(array[0], " ")
    for i := 1; (i+1) < n; i++ {
    	var t float64
        z := float64(array[i-1] + array[i] + array [i+1])
        t = z/3
        fmt.Print(t, " ")
    }
    fmt.Print(array[n-1])
}
