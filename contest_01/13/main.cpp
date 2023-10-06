#include <iostream>

using namespace std;
int main()
{
	int x;
	int i;
	int l;
	int maxlevel;
	bool check;

	i = 1;
	l = 1;
	maxlevel = 2;
	check = true;

	cin >> x;

	while (i <= x) {
		for (int j = 1; j <= l; j++) {
			if (i <= x) {
				cout << i << " ";
				i++;
			}
		}

		if (l == maxlevel) {
			check = false;
			maxlevel++;
		}

		if (l == 1) {
			check = true;
		}

		if (check == true) {
			l++;
		}

		if (check == false) {
			l--;
		}

		cout << endl;

	}

	return 0;
}
