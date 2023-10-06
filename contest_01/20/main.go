package main
import "fmt"
import "strings"

func implContains(sl []string, name string) bool {
    for _, value := range sl {
        if value == name {
            return true
        }
    }
    return false
}

func main() {
    var a, b string
    fmt.Scan(&a, &b)
    arr_a := strings.Split(a, "")
    arr_b := strings.Split(b, "")
    k := 0
    for i := 0; i < len(arr_b); i++ {
        if implContains(arr_b, arr_a[i]) {
            k++
            for j := 0; j < len(arr_b); j++ {
                if arr_a[i] == arr_b[j] {
                    arr_b[j] = "n/a"
                    break
                }
            }
        }
    }
    if len(arr_a) == k {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}
