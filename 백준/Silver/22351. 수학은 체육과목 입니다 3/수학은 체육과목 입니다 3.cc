#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    

    for (int i = 1; i < 1000; i++) {
        string a = to_string(i);
        string sum = to_string(i);

        if (sum == s) {
            cout << sum << " " << sum << "\n";
            exit(0);
        }

        for (int j = i + 1; j < 1000; j++) {
            sum += to_string(j);
            if (sum == s) {
                cout << a << " " << j << "\n";
                exit(0);
            }
        }
    }
    

    return 0;
}