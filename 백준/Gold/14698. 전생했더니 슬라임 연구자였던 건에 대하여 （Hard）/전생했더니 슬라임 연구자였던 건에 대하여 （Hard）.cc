#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int k;
const ll mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		ll res = 1;
		cin >> k;
		for (int i = 0; i < k; i++) {
			ll num;
			cin >> num;
			pq.push(num);
		}

		while (pq.size() > 1) {
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			res *= (((a % mod) * (b % mod)) % mod);
			res %= mod;
			pq.push(a * b);
		}

		cout << res % mod << "\n";
	}

	return 0;
}