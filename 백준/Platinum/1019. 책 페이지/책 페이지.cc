#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll res[15];

void calc(ll num, ll k) {
	while (num > 0) {
		ll digit = num % 10;
		res[digit] += k;
		num /= 10;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	ll left = 1;
	ll right = n;
	ll k = 1;

	while (left <= right) {
		while (left % 10 != 0) {
			if (left > right) break;
			calc(left, k);
			left++;
		}

		while (right % 10 != 9) {
			if (left > right) break;
			calc(right, k);
			right--;
		}

		if (left > right) break;

		// 남은 구간 계산
		for (int i = 0; i <= 9; i++) {
			res[i] += (right / 10 - left / 10 + 1) * k;
		}

		left /= 10;
		right /= 10;
		k *= 10;
	}

	for (int i = 0; i <= 9; i++) {
		cout << res[i] << " ";
	}
	cout << "\n";

	return 0;
}