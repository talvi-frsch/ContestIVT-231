package main
import "fmt"
import "math"

func main() {
    var dub float64
    var topol float64
    var chel float64
    var topolk float64
    var dubk float64
    
    dub = 20
    topol = 32
    chel = 0.5 * 365
    
    dubk = chel / dub
    topolk = chel / topol
    
    fmt.Print(chel, " ")
    fmt.Print(math.Ceil(topolk), " ")
    fmt.Print(math.Ceil(dubk))
}
