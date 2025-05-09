#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int alpha[27];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s;
    for (auto it : s) {
        alpha[it - 'A']++;
    }

    if (alpha['M' - 'A'] && alpha['O' - 'A'] && alpha['B' - 'A'] && alpha['I' - 'A'] && alpha['S' - 'A']) cout << "YES";
    else cout << "NO";

    return 0;
}