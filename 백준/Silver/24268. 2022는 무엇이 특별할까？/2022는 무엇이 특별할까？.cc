#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, d;
string v;
string tmp;

ll change_num(string digit_num, ll digit) {
	ll ans = 0;
	for (int i = 0; i < digit_num.size(); i++) {
		ans += (digit_num[i] - '0') * pow(digit, digit_num.size() - 1 - i);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> d;
	for (int i = 0; i < d; i++) {
		v += i + '0';
	}


	do {
		if (v[0] == '0') continue;
		ll ctmp = change_num(v, d);
		if (ctmp > n) {
			cout << ctmp << "\n";
			exit(0);
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << -1;

	return 0;
}