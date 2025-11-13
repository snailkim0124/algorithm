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
ll visited[100005];
vector<pll> v; // 값, 인덱스
ll res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);

	ll mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		mn = min(mn, v[i].first);
		v[i].second = i;
	}

	sort(all(v));

	// 최소후보를 계속 탐색
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ll cnt = 0;
			ll idx = i;
			while (1) {
				if (visited[idx]) break;
				visited[idx] = 1;
				cnt++;
				res += v[idx].first;
				idx = v[idx].second; // 인덱스 이동
			}

			// 1. 그냥 최솟값이랑 교환 or 2. 가장 작은 원소를 바꾸고 다시 원래 자리
			res += min(mn * (cnt + 1) + v[i].first, v[i].first * (cnt - 2));
		}
	}

	cout << res << "\n";

	//cout << "==============\n";
	//for (auto it : candi) {
	//	cout << it << " ";
	//}
	//
	return 0;
}