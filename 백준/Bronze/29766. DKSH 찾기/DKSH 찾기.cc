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
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    for (int i = 0; i < s.size() - 3; i++) {
        string tmp = s.substr(i, 4);
        if (tmp == "DKSH") {
            cnt++;
        }
    }
    
    cout << cnt << "\n";

    return 0;
}