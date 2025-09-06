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

vector<int> kmp(string& t, string& p) {
    vector<int> f = failure(p);
    vector<int> res;
    int j = 0;

    for (int i = 0; i < t.size(); i++) {
        while (j > 0 && t[i] != p[j]) j = f[j - 1];
        if (t[i] == p[j]) {
            if (j == p.size() - 1) {
                res.push_back(i - p.size() + 2);
                j = f[j];
            }
            else j++;
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string t, p;
    getline(cin, t);
    getline(cin, p);

    vector<int> ans = kmp(t, p);

    cout << ans.size() << "\n";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}