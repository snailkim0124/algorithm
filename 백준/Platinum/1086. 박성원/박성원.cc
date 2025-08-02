#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
string v[20];
ll dp[1 << 15][105]; // bit, k
ll tenpow[55]; // 10몇제곱이 k로 나눠지는 모듈러 값
ll modv[20];// v가 k로 나눠지는 모듈러 값
ll k;

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}

ll factorial(ll num) {
	ll res = 1;
	for (int i = 2; i <= num; i++) {
		res *= i;
	}
	return res;
}

ll get_mod(string s) {
	ll res = 0;
	for (auto it : s) {
		res = ((res * 10) % k + (it - '0')) % k;
	}

	return res;
}

ll go(ll bit, ll check) {
	if (bit == (1 << n) - 1) {
		return !check ? 1 : 0;
	}

	if (dp[bit][check] != -1) return dp[bit][check];
	dp[bit][check] = 0;

	for (int i = 0; i < n; i++) {
		if (!(bit & (1 << i))) {
			ll tmp = (check * tenpow[v[i].size()] + modv[i]) % k;
			dp[bit][check] += go(bit | (1 << i), tmp);
		}
	}

	return dp[bit][check];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> k;

	for (int i = 0; i < n; i++) {
		modv[i] = get_mod(v[i]);
	}

	tenpow[0] = 1 % k;
	for (int i = 1; i <= 50; i++) {
		tenpow[i] = (tenpow[i - 1] * 10) % k;
	}

	memset(dp, -1, sizeof(dp));
	ll p = go(0, 0);
	ll q = factorial(n);
	ll GCD = gcd(p, q);

	cout << p / GCD << "/" << q / GCD;

	return 0;
}