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
	if (n <= 2) {
		cout << 0 << "\n";
		exit(0);
	}

	ll sum = 1;
	for (int i = 4; i <= n; i++) {
		sum += (i - 1) / 2;
	}

	cout << sum << "\n";
	

	return 0;
}