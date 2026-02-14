#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
string s;

vector<int> failure(string& p) {
    vector<int> f(p.size());
    int j = 0;

    for (int i = 1; i < p.size(); i++) {
        while (j > 0 && p[i] != p[j]) j = f[j - 1];
        if (p[i] == p[j]) f[i] = ++j;
    }

    return f;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	while (1) {
		cin >> n;
		if (!n) break;

		cin >> s;

        vector<int> f = failure(s);
		string ans = s;

		for (int i = f[f.size() - 1]; i < n; i++) {
			ans += s[i];
		}

		cout << ans << "\n";

	}

	
	return 0;
}