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
    cin.tie(NULL);

    cin >> s;
    string tmp = s;
    reverse(all(tmp));
    
    cout << (tmp == s ? "true" : "false");

    
    return 0;
}