#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double a, b;
    double c;

    cin >> a;
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));

    cout.precision(17);
    cout << c;
}
