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

ll query(ll p) {
	cout << "? " << p << endl;
	ll res;
	cin >> res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	ll left = 1;
	ll right = n;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll q = query(mid);
		if (q == -1) {
			left = mid + 1;
		}
		else if (q == 0) {
			cout << "= " << mid << endl;
			break;
		}
		else if (q == 1) {
			right = mid - 1;
		}
	}
	

	return 0;
}