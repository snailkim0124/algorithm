#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
string s;
ll sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> s;
    string tmp = "0";
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            tmp += s[i];
        }
        else {
            sum += stoll(tmp);
            tmp = "0";
        }
    }
    
    sum += stoll(tmp);

    cout << sum << "\n";

    return 0;
}