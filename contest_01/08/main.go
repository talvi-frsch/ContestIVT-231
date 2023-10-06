package main
import "fmt"

func main() {
    var a int32
    var b int32
    var c int32
    var temp_max int32
    
    fmt.Scan(&a)
    fmt.Scan(&b)
    fmt.Scan(&c)
    
    if a > b {
        temp_max = a
    }else{
        temp_max = b
    }
    if temp_max > c {
        fmt.Println(temp_max)
    }else{
        fmt.Println(c)
    }
    
}
