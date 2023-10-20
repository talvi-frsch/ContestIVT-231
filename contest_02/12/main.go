package main

import "fmt"

// Мой код
func fill(maze [][]int) {
    rows := len(maze)
    cols := len(maze[0])

    for i := 0; i < rows; i++ {
        for j := 0; j < cols; j++ {
            if maze[i][j] != -1 {
                if i+1 < rows && maze[i+1][j] == -1 {
                    maze[i][j]++
                }
                if i+1 < rows && j-1 >= 0 && maze[i+1][j-1] == -1 {
                    maze[i][j]++
                }
                if j+1 < cols && maze[i][j+1] == -1 {
                    maze[i][j]++
                }
                if j+1 < cols && i+1 < rows && maze[i+1][j+1] == -1 {
                    maze[i][j]++
                }
                if i-1 >= 0 && maze[i-1][j] == -1 {
                    maze[i][j]++
                }
                if i-1 >= 0 && j+1 < cols && maze[i-1][j+1] == -1 {
                    maze[i][j]++
                }
                if j-1 >= 0 && maze[i][j-1] == -1 {
                    maze[i][j]++
                }
                if j-1 >= 0 && i-1 >= 0 && maze[i-1][j-1] == -1 {
                    maze[i][j]++
                }
            }
        }
    }
}
// Конец моего кода

func main() {
    var rows, cols int
    fmt.Scanf("%d %d\n", &rows, &cols)
    
    // Создаём срез и заполняем его данными о расположении мин
    maze := make([][]int, rows, rows)
    for i := range maze {
        maze[i] = make([]int, cols, cols)
        for j := range maze[i] {
            fmt.Scanf("%d", &maze[i][j])
        }
    }
    
    // Заполняем игровое поле подсказками
    fill(maze)
    
    // Выводим на экран
    for _, row := range maze {
         for _, cell := range row {
             fmt.Printf("%3d", cell)
        }
        fmt.Println()
    }
}
