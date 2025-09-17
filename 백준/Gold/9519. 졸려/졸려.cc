#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll x;
string s;
ll cnt; // 주기

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x;
    cin >> s;

    string tmp = s;

    while (1) {
        string even = "", odd = "";
        int sz = tmp.size();

        if (tmp.size() % 2 == 1) sz--;

        for (int i = 0; i < tmp.size(); i += 2) {
            even += tmp[i];
        }

        for (int i = sz - 1; i >= 0; i -= 2) {
            odd += tmp[i];
        }

        tmp = even + odd;
        cnt++;

        if (tmp == s) break;
    }
    
    x %= cnt;

    while (x--) {
        string even = "", odd = "";
        int sz = tmp.size();

        if (tmp.size() % 2 == 1) sz--;

        for (int i = 0; i < tmp.size(); i += 2) {
            even += tmp[i];
        }

        for (int i = sz - 1; i >= 0; i -= 2) {
            odd += tmp[i];
        }

        tmp = even + odd;
    }

    cout << tmp << "\n";

    return 0;
}