#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin, s);
    if (s.find("D2") != string::npos || s.find("d2") != string::npos) {
        cout << "D2";
    }
    else cout << "unrated";

    return 0;
}