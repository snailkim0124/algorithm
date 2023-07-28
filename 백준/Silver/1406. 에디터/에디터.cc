#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

string s;
stack<char> leftst;
stack<char> rightst;
int m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        leftst.push(s[i]);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        char command;
        cin >> command;
        if (command == 'L') {
            if (leftst.size() != 0) {
                rightst.push(leftst.top());
                leftst.pop();
            }
        }
        if (command == 'D') {
            if (rightst.size() != 0) {
                leftst.push(rightst.top());
                rightst.pop();
            }
        }
        if (command == 'B') {
            if (leftst.size() != 0) {
                leftst.pop();
            }

        }
        if (command == 'P') {
            char a;
            cin >> a;
            leftst.push(a);
        }
    }
    while (leftst.size() != 0) {
        rightst.push(leftst.top());
        leftst.pop();
    }

    while (rightst.size() != 0) {
        cout << rightst.top();
        rightst.pop();
    }
    return 0;
}