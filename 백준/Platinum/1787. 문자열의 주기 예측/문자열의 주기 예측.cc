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

    ll n, sum = 0;
    string s;
    cin >> n;
    cin >> s;

    vector<int> f = failure(s);
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        if (f[i]) {
            // 최소 주기 찾기
            if (dp[f[i] - 1]) dp[i] = dp[f[i] - 1];
            else dp[i] = f[i];
            sum += (i + 1) - dp[i];
        }
    }

    cout << sum << "\n";

    return 0;
}