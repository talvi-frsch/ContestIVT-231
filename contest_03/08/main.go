package main

import "fmt"

func findSingleNumber(numbers []int) int {
    res := 0
    for _, num := range numbers {
        res ^= num
    }
    return res
}

func main() {
    var a int
    fmt.Scan(&a)

    numbers := make([]int, a)
    for i := 0; i < a; i++ {
        fmt.Scan(&numbers[i])
    }

    fmt.Println(findSingleNumber(numbers))
}
