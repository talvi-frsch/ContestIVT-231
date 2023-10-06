package main
import (
	"fmt"
	"strings"
	"bufio"
	"os"
	"sort"
)
func contains(s []string, e string) bool {
    for _, a := range s {
        if a == e {
            return true
        }
    }
    return false
}

func main() {
	in := bufio.NewReader(os.Stdin)
	str, er := in.ReadString('\n')
	er = er
	words := strings.Fields(str)
	var array [] string
	for i := 0; i < len(words); i++ {
	    if words[i] == "end" {
	        for j := i + 1; j < len(words); j++ {
	            words[j] = "end"
	        }
	        break
	    }
	}
	for i := 0; i < len(words); i++ {
	    if words[i] != "end" {
	        in_words := contains(words[i+1: len(words) - 1], words[i])
	        out_array := contains(array, words[i])
	        if (in_words == true) && (out_array == false) {
	        array = append(array, words[i])
	        }
	    } else {
	        break
	    }
	}
	sort.Strings(array)
	for i := 0; i < len(array); i++ {
	    if i == (len(array) - 1) {
	        fmt.Print(array[i])
	    } else {
	        fmt.Print(array[i], " ")
	    }
	}
}
