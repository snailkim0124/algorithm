#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll N, T, K;
priority_queue<pll> pq;
ll sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> T >> K;
	for (int i = 0; i < N; i++) {
		ll cmd, t, f;
		cin >> cmd >> t;
		if (cmd == 1) {
			cin >> f;
			pq.push({ f, -t });
		}
		else if (cmd == 2) {
			ll cnt = 0;
			while (!pq.empty() && cnt < K) {
				auto [f, tt] = pq.top();
				pq.pop();
				tt = -tt;

				if (t - tt > T) continue;
				sum += f;
				cnt++;
			}
		}
	}

	cout << sum << "\n";
	
	return 0;
}