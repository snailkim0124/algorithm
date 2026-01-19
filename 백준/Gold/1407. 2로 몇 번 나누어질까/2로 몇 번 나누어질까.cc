#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll a, b;
ll res;

ll go(ll num) {
	ll sum = 0;

	ll tmp = 1;
	while (num > 0) {
		ll cnt = (num + 1) / 2; // 홀수 개수

		sum += cnt * tmp;
		num >>= 1;
		tmp <<= 1;
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	
	cout << go(b) - go(a - 1) << "\n";

	return 0;
}