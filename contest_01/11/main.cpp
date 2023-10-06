#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	float A, B, C;

	cin >> A;
	cin >> B;
	cin >> C;

	if (abs(A - B) < abs(A - C)) cout << "B " << abs(A - B);
	else cout << "C " << abs(A - C);
}
