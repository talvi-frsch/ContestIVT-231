#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    setlocale(LC_ALL, "RU");

    float p;
    
    p = pow(12, 0.5) * (1 - (1 / pow(3, 2)) + (1 / (5 * pow(3, 2))) - (1 / (7 * pow(3, 3))) + (1 / (9 * pow(3, 4))) - (1 / (11 * pow(3, 5))));
    cout << p;
}
