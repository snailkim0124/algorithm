#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void hanoi(ll n, ll k, int a, int b, int c) {
	ll m = pow(2, n - 1);

	if (k == m) {
		cout << a << " " << c << "\n";
		return;
	}
	else if (k < m) {
		hanoi(n - 1, k, a, c, b);
	}
	else {
		hanoi(n - 1, k - m, b, a, c);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n, k;
	cin >> n >> k;

	hanoi(n, k, 1, 2, 3);

	return 0;
}