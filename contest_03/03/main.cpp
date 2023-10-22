#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int priority(char a) {
    if (a == '+' || a == '-') {
        return 1;
    }
    else if (a == '*' || a == '/' || a == '%') {
        return 2;
    }
    else if (a == '^') {
        return 3;
    }
    return 0;
}

string infix_to_rpn(const string& infix) {
    stack<char> opers;
    string stack_;

    for (char c : infix) {
        if (isdigit(c)) {
            stack_ += c;
        }
        else if (c == '(') {
            opers.push(c);
        }
        else if (c == ')') {
            while (!opers.empty() && opers.top() != '(') {
                stack_ += " ";
                stack_ += opers.top();
                opers.pop();
            }
            opers.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
            while (!opers.empty() && (priority(opers.top()) > priority(c) ||
                (priority(opers.top()) == priority(c) && c != '^'))) {
                stack_ += " ";
                stack_ += opers.top();
                opers.pop();
            }
            stack_ += " ";
            opers.push(c);
        }
    }

    while (!opers.empty()) {
        stack_ += " ";
        stack_ += opers.top();
        opers.pop();
    }

    return stack_;
}

int main() {
    string infix;
    getline(cin, infix);

    string stack_ = infix_to_rpn(infix);
    cout << stack_;

    return 0;
}
