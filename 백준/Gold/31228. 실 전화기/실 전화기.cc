#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n, k;
ll tmp;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	if (n % k == 0) {
		cout << 0;
		exit(0);
	}

	tmp = gcd(n, k);

	if (tmp != 1) {
		n /= tmp;
		k /= tmp;
	}

	if (k > n / 2) {
		cout << n * (n - k - 1);
	}
	else cout << n * (k - 1);

	return 0;
}