package main
import (
    "bufio"
    "fmt"
    "os"
)

//Мой код
import "strconv"

func isLucky(number string) bool {
	l := 0
	r := 0

	for _, str := range number[:3] {
		temp, _ := strconv.Atoi(string(str))
		l += temp
	}
	
	for _, str := range number[3:] {
		temp, _ := strconv.Atoi(string(str))
		r += temp
	}
	
	return l == r
}
//Конец моего кода

func main() {
    number, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isLucky( number[:len(number)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
