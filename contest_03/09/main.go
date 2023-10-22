package main

import "fmt"

func para(mas []int, x int) (int, int) {
    checked := make(map[int]bool)

    for _, num := range mas {
        razn := x - num
        if checked[razn] {
            if num < razn {
                return num, razn
            }
        return razn, num
        }
    checked[num] = true
    }
    return 0, 0
}

func main() {
    var n, x int
    fmt.Scan(&n, &x)

    mas := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&mas[i])
    }

    a, b := para(mas, x)
    fmt.Print(a, b)
}
