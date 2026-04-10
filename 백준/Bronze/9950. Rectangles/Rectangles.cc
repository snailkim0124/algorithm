#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int l, w, a;

void solve() {
	if (l == 0) {
		cout << a / w << " " << w << " " << a << "\n";
	}
	else if (w == 0) {
		cout << l << " " << a / l << " " << a << "\n";
	}
	else if (a == 0) {
		cout << l << " " << w << " " << l * w << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> l >> w >> a;
		if (!l && !w && !a) break;
		solve();
	}
	
	
	return 0;
}