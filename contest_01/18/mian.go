package main
import "fmt"

func main() {
	var n, i int
    array := [26] string {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}
    fmt.Scan(&n)
    var str string
    for {
    	if n%26 == 0 {
        	str = "Z" + str
            n = n/26 - 1
		} else {
        	i = n % 26
            str = array[i-1] + str
            n = n/26
        }
        if n <= 0 {
        	break
        }
    }
    fmt.Print(str)
}
