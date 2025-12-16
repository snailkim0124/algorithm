#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1'000'000'007;

void solve() {
	ll n;
	cin >> n;
	if (n < 4 || n == 6) {
		cout << 0 << "\n";
	}
	else if (n == 4) {
		// {1,2,1,0}, {2,0,2,0}
		cout << 2 << "\n";
	}
	else {
		// a0 = n - 4, a1 = 2, a2 = 1, an-4 = 1, 나머지 = 0
		cout << 1 << "\n";
	}

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