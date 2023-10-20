#include <iostream>
#include <vector>
#include <string>

// Мой код
bool is_can_exit_from_maze(std::vector<std::string>& maze, int row, int col) {
	if (maze[row][col] == 'E') return true;
	maze[row][col] = 'x';
	if (maze[row + 1][col] != 'x' && maze[row + 1][col] != '#') return 0 + is_can_exit_from_maze(maze, row + 1, col);
	if (maze[row - 1][col] != 'x' && maze[row - 1][col] != '#') return 0 + is_can_exit_from_maze(maze, row - 1, col);
	if (maze[row][col + 1] != 'x' && maze[row][col + 1] != '#') return 0 + is_can_exit_from_maze(maze, row, col + 1);
	if (maze[row][col - 1] != 'x' && maze[row][col - 1] != '#') return 0 + is_can_exit_from_maze(maze, row, col - 1);
	return false;
}
// Конец моего кода

int main(){
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода
    
    std::vector<std::string> maze(rows);
    for(auto& line : maze) std::getline(std::cin, line);
    
    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}
