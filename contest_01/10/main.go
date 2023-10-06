package main;
import "fmt"

func main() {

    var res int8
    var danet string
    
    fmt.Scan(&danet)

    if danet == "Да" {
        res = res + 100
    }else if danet == "Нет"{
        res = res + 0
    }

    fmt.Scan(&danet)

    if danet == "Да" {
        res = res + 10
    }else if danet == "Нет"{
        res = res + 0
    }

    fmt.Scan(&danet)

    if danet == "Да" {
        res = res + 1
    }else if danet == "Нет"{
        res = res + 0
    }

    if res == 0 {fmt.Println("Кот")}
    if res == 1 {fmt.Println("Жираф")}
    if res == 10 {fmt.Println("Курица")}
    if res == 11 {fmt.Println("Страус")}
    if res == 100 {fmt.Println("Дельфин")}
    if res == 101 {fmt.Println("Плезиозавры")}
    if res == 110 {fmt.Println("Пингвин")}
    if res == 111 {fmt.Println("Утка")}
}
