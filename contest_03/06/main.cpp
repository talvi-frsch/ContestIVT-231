#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int a;
    cin >> a;

    unordered_map<string, int> balances;

    for (int i = 0; i < a; i++) {
        string info;
        cin >> info;


        istringstream iss(info);
        string login;
        int balance;
        getline(iss, login, ';');
        iss >> balance;

        balances[login] = balance;
    }

    int b;
    cin >> b;
    vector<int> results;

    for (int i = 0; i < b; i++) {
        string zapros;
        cin >> zapros;
        if (balances.find(zapros) != balances.end()) {
            results.push_back(balances[zapros]);
        }
    }

    for (int balance : results) {
        cout << balance << " ";
    }

    return 0;
}
