package main
import "fmt"

func main() {
    var a float64
    var b float64
    var res float64
    
    fmt.Scan(&a)
    fmt.Scan(&b)
    
    res = a * b
    
    fmt.Println(res)
}
