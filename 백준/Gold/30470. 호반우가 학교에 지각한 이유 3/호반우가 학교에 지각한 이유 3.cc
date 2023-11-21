#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
stack<pair<ll, ll>> st; // (길이, 개수)
ll cnt;
ll res;
ll mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	st.push({ 0,0 });
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		if (a == 1) {
			st.push({ b, 1 });
			mx = max(mx, b);
		}
		else if (a == 2) {
			ll sum = 0;
			while (!st.empty() && st.top().first >= max(0LL, mx - b)) {
				sum += st.top().second;
				st.pop();
			}
			st.push({ max(0LL, mx - b), sum });
			mx = st.top().first;
		}
	}

	while (!st.empty()) {
		//cout << st.top().first << " " << st.top().second << "\n";
		res += st.top().first * st.top().second;
		st.pop();
	}

	cout << res;

	return 0;
}