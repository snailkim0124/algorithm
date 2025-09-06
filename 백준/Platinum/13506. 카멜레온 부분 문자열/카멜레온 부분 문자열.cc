#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<int> failure(string& p) {
    vector<int> f(p.size());
    int j = 0;

    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    return f;
}

bool kmp(string& t, string& p) {
    vector<int> f = failure(p);
    vector<int> res;
    int j = 0;

    for (int i = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                return true;
            }
            else j++;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    vector<int> f = failure(s);

    int sz = f[s.size() - 1];
    if (sz == 0) {
        cout << -1 << "\n";
        exit(0);
    }

    for (int i = 0; i < s.size() - 1; i++) {
        if (f[i] == sz) {
            cout << s.substr(0, sz) << "\n";
            exit(0);
        }
    }

    // 더 짧은 카멜레온 찾기
    sz = f[sz - 1];
    if (sz == 0) cout << -1 << "\n";
    else cout << s.substr(0, sz) << "\n";

    return 0;
}