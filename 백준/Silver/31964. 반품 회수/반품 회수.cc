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
ll x[3005], t[3005];
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	res = x[n - 1];

	for (int i = n - 1; i >= 0; i--) {
		if (res < t[i]) res += t[i] - res;
		if (i >= 1) res += x[i] - x[i - 1];
	}

	res += x[0];

	cout << res << "\n";
	
	return 0;
}