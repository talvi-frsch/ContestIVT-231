package main
import (
    "bufio"
    "fmt"
    "os"
)

// Мой код
import "strings"

func isPalindrome(str string) bool {
    str = strings.ToLower(str)
    
    clearStr := ""
    
    for _, char := range str {
        if ((char >= 'a' && char <= 'z') || (char >= '0' && char <= '9')) {
            clearStr += string(char)
        }
    }
    
    for i := 0; i < (len(clearStr) / 2); i++ {
        if clearStr[i] != clearStr[len(clearStr) - i - 1] {
            return false
        }
    }
    return true
}
// Мой код

func main() {
    line, _  := bufio.NewReader(os.Stdin).ReadString('\n')
    if isPalindrome( line[:len(line)-1] ){  // Обрезаем \n в конце строки
        fmt.Println("YES")
    }else{
        fmt.Println("NO")
    }
}
