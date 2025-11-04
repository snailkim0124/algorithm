#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll k, n;
vector<int> prime;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> n;
	prime.resize(k);

	for (int i = 0; i < k; i++) {
		cin >> prime[i];
	}

	priority_queue<ll, vector<ll>, greater<ll>> pq;
	pq.push(1);
	ll ans = 1;

	for (int i = 0; i < n + 1; i++) {
		ans = pq.top();
		pq.pop();

		for (auto it : prime) {
			pq.push(ans * it);

			if (ans % it == 0) break;
		}
	}

	cout << ans << "\n";

	return 0;
}