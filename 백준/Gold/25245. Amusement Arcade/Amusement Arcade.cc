#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	if (n == 1) {
		cout << 1 << "\n";
		exit(0);
	}
	

	n--;
	ll cnt = 0;
	ll tmp = n;
	while (tmp > 0) {
		if (tmp & 1) cnt++;
		tmp >>= 1;
	}

	if (cnt == 1) {
		cout << 1 << "\n";
	}
	else if (cnt == 2) {
		// 가장 작은 비트값
		ll low = n & -n;
		cout << low + 1 << "\n";
	}
	else cout << "impossible\n";

	

	return 0;
}