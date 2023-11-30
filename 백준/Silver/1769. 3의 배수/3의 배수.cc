#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    while (1) {
        ll sum = 0;
        if (s.size() == 1) break;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
        }
        s = to_string(sum);
        cnt++;
    }

    cout << cnt << "\n";
    if (stoi(s) == 1 || stoi(s) == 2 || stoi(s) == 4 || stoi(s) == 5 || stoi(s) == 7 || stoi(s) == 8) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }

    return 0;
}
