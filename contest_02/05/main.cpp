#include <iostream>

struct Complex{
  double re;  // Действительная часть
  double im;  // Мнимая часть
};

// Мой код
#include <string>
#include <sstream>

Complex make_complex(const std::string &str) {
    Complex c;
    std::string tmp;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] != ' ')
            tmp += str[i];
    std::istringstream iss(tmp);
    iss >> c.re >> c.im;
    return c;
}

Complex sum (const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;
    return result;
}

Complex sub ( const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re - c2.re;
    result.im = c1.im - c2.im;
    return result;
}

Complex mul (const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re * c2.re - c1.im * c2.im;
    result.im = c1.re * c2.im + c1.im * c2.re;
    return result;
}

Complex div (const Complex& c1, const Complex& c2) {
    Complex result;
    double d = c2.re * c2.re + c2.im * c2.im;
    result.re = (c1.re * c2.re + c1.im * c2.im) / d;
    result.im = (c1.im * c2.re - c1.re * c2.im) / d;
    return result;
}

void print(const Complex& c) {
    std::cout << c.re << (c.im < 0.0 ? "-" : "+") << std::abs(c.im) << "j" << std::endl;
}
// Конец моего кода

int main()
{
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);
    
    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);
    
    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));
}
