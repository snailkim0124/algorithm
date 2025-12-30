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
ll v[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll sum = 0;
	ll tmp = 0;
	for (int i = n - 1; i >= 0; i--) {
		tmp = min(tmp + 1, v[i]);
		sum += tmp;
	}

	cout << sum << "\n";
	
	return 0;
}