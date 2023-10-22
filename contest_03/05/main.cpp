#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a;
    cin >> a;

    unordered_map<string, int> count;

    for (int i = 0; i < a; i++) {
        string word;
        cin >> word;
        count[word]++;
    }

    vector<string> chastoe;
    int max = 0;

    for (auto& pair : count) {
        if (pair.second > max) {
            chastoe.clear();
            chastoe.push_back(pair.first);
            max = pair.second;
        }
        else if (pair.second == max) {
            chastoe.push_back(pair.first);
        }
    }

    sort(chastoe.begin(), chastoe.end());

    for (const string& word : chastoe) {
        cout << word << " ";
    }

    return 0;
}
