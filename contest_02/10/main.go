package main
import "fmt"

// Мой код
func copyArray(nov, star []int){
	for i := range nov {
	    star[i] = nov[i]
    }
}

func shift(arr []int, steps int) {
	steps = steps % 10
	if steps < 0 {
		steps = 10 + steps
	}

	temp := make([]int, 10)

	for i := 0; i < 10; i++ {
		newIndex := (i + steps) % 10
		if newIndex < 0 {
			newIndex += 10
		}
		temp[newIndex] = arr[i]
	}
	copyArray(temp, arr)
}
// Конец моего кода

func main(){
    var steps int
    fmt.Scan(&steps)

    var data [10]int
    for index := range data{
        fmt.Scan(&data[index])
    }

    shift(data[:], steps);
    for _, value := range data{
        fmt.Printf("%d ", value)
    }
}
