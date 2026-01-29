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
ll depth[300005];
set<ll> s;
ll sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		auto it = s.lower_bound(num);
		ll left_depth = -1;
		ll right_depth = -1;

		// 가장 깊은 곳 찾기
		if (it != s.end()) {
			right_depth = depth[*it];
		}

		if (it != s.begin()) {
			left_depth = depth[*prev(it)];
		}
		ll mx = max(right_depth, left_depth);

		depth[num] = mx + 1;
		sum += depth[num];

		cout << sum << "\n";
		s.insert(num);
	}
	
	return 0;
}