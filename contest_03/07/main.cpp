#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    ifstream file("data.txt");

    string target;
    cin >> target;

    map<string, int> count;
    string word;

    while (file >> word) {
        if (word == target) {
            string nextword;
            file >> nextword;
            if (nextword != "stopword") {
                count[nextword]++;
            }
        }
    }

    vector<pair<string, int>> sorted;

    for (const auto& pair : count) {
        sorted.emplace_back(pair.first, pair.second);
    }

    sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
        return a.second != b.second ? a.second > b.second : a.first < b.first;
        });

    if (sorted.empty()) {
        cout << "-" << endl;
    }
    else {
        for (int i = 0; i < 3 && i < sorted.size(); ++i) {
            cout << sorted[i].first << " ";
        }
        cout << endl;
    }
}
