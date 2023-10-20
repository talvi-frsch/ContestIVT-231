#include <iostream>

// Мой код
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    } 
    else if (number == 2) {
        return true;
    } 
    else {
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
}
// Конец моего кода

int main(){
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}
