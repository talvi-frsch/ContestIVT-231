#include <iostream>

using namespace std;
int main()
{
    double a;
    double b;
    double res;

    cin >> a;
    cin >> b;

    res = a / b;

    cout.precision(17);
    cout << res;
}
