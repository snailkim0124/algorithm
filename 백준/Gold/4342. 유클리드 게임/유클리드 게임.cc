#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;

void solve() {
	int idx = 0;

	while (1) {
		if (n < m) swap(n, m);

		if (n % m == 0) {
			if (idx % 2 == 0) cout << "A wins\n";
			else cout << "B wins\n";
			break;
		}
		else {
			int q = n / m;
			if (q >= 2) {
				if (idx % 2 == 0) cout << "A wins\n";
				else cout << "B wins\n";
				break;
			}
			else {
				n -= q * m;
			}
		}

		idx++;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (!n && !m) break;
		if (n < m) swap(n, m);
		solve();
	}

	return 0;
}