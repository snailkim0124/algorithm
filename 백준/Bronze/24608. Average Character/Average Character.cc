#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        sum += (int)(s[i]);
    }
    
    cout << (char)(sum / s.size());

    return 0;
}