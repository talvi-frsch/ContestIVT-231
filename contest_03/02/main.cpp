#include <iostream>
#include <string>

using namespace std;
string get_string(char end = '\n') {
	string text;
	getline(cin, text, end);
	return text;
}
bool predicate(string text) {
	int count1 = 0, count2 = 0, count3 = 0;
	string prev_sym = "";
	for (char elem : text) {
		if (count1 < 0 || count2 < 0 || count3 < 0) return false;
		if (elem == '(') {
			count1++;
			prev_sym = ")" + prev_sym;
			continue;
		}
		if (elem == ')') {
			count1--;
			if (prev_sym[0] != elem) return false;
			prev_sym = prev_sym.substr(1);
			continue;
		}

		if (elem == '[') {
			count2++;
			prev_sym = "]" + prev_sym;
			continue;

		}
		if (elem == ']') {
			count2--;
			if (prev_sym[0] != elem) return false;
			prev_sym = prev_sym.substr(1);
			continue;

		}
		if (elem == '{') {
			count3++;
			prev_sym = "}" + prev_sym;
			continue;

		}
		if (elem == '}') {
			count3--;
			if (prev_sym[0] != elem) return false;
			prev_sym = prev_sym.substr(1);
			continue;
		}
	}
	return count1 == 0 && count2 == 0 && count3 == 0;
}

int main() {
	string text = get_string('!');
	predicate(text) ? cout << "YES" : std::cout << "NO";
}
