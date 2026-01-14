#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, q;
ll arr[10005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	while (q--) {
		ll cmd, p, x;
		cin >> cmd >> p >> x;
		if (cmd == 1) {
			arr[p] += x;
		}
		else if (cmd == 2) {
			ll sum = 0;
			for (int i = p; i <= x; i++) {
				sum += arr[i];
			}
			cout << sum << "\n";
		}
	}
	

	return 0;
}