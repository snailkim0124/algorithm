#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	ll a, b;
	cin >> a >> b;

	if (b == 1) cout << 0 << "\n";
	else if (b % a == 0 && b / a >= 2) cout << 1 << "\n";
	else cout << 0 << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	
	return 0;
}