#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n, mx = -987654321, mn = 987654321;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			mx = max(mx, num);
			mn = min(mn, num);
		}

		cout << mn << " " << mx << "\n";
	}



	return 0;
}