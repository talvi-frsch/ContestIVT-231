#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double i;
	float h;
	float m;

	cin >> m;
	cin >> h;
	i = m / pow(h, 2);
	cout.precision(17);
	cout << i;

}
