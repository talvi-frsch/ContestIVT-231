#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	string nstr;
	short povt;
	
	cin >> str;

	povt = 1;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[i + 1]) {
			if (povt == 1) {
				cout << str[i];
			}
			if (povt > 1) {
				cout << str[i] << povt;
				povt = 1;
			}
		}
		if (str[i] == str[i + 1]) {
			povt = povt + 1;
		}
	}
}
