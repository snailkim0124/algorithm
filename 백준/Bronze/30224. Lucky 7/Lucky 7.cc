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

    cin >> s;
    bool chk1 = (s.find("7") != string::npos);
    bool chk2 = (stoll(s) % 7 == 0);
    if (chk1 && chk2) cout << 3;
    else if (chk1 && !chk2) cout << 2;
    else if (!chk1 && chk2) cout << 1;
    else cout << 0;
   
    return 0;
}