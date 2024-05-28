#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first;
	}

	sort(v.begin(), v.end(), greater<>());
	res = v[0].first;

	for (auto it : v) {
		if (res < it.first) res -= it.second;
		else {
			// 시간 초기화
			res = it.first - it.second;
			if (res < 0) {
				cout << -1;
				exit(0);
			}
		}
	}

	cout << res;

	return 0;
}