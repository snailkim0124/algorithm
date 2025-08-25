#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
const ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		ll a, b, m;
		cin >> a >> b >> m;
		if (m == 0) {
			if (a == 0 && b == 0) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
	}



	return 0;
}