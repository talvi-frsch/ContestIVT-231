#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int count1, count2;
    string words1, words2;
    cin >> count1;
    cin.ignore();
    getline(cin, words1);
    cin >> count2;
    cin.ignore();
    getline(cin, words2);

    set<string> set1, set2;
    stringstream ss1(words1), ss2(words2);
    string word;
    while (ss1 >> word) {
        set1.insert(word);
    }
    while (ss2 >> word) {
        set2.insert(word);
    }

    set<string> povtwords;
    for (const string& word : set1) {
        if (set2.count(word) > 0) {
            povtwords.insert(word);
        }
    }

    if (povtwords.empty()) {
        cout << -1 << endl;
    }
    else {
        for (const string& word : povtwords) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
