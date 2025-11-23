#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s, t, ans;
int alpha[27];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> t;
	for (auto it : s) {
		alpha[it - 'a']++;
	}

	for (auto it : t) {
		if (!alpha[it - 'a']) ans += it;
	}

	cout << ans << "\n";
	
	return 0;
}