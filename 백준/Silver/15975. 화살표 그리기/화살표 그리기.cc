#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll arr[100005];
ll sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<ll, ll>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].second >> v[i].first; // 색깔, 위치
	}

	sort(v.begin(), v.end());

	/*cout << "----------------\n";
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			if (v[i].first == v[i - 1].first) {
				sum += v[i].second - v[i - 1].second;
			}
			continue;
		}
		if (v[i].first == v[i + 1].first) {
			if (i != 0 && v[i].first == v[i - 1].first) {
				sum += min(v[i].second - v[i - 1].second, v[i + 1].second - v[i].second);
			}
			else {
				sum += v[i + 1].second - v[i].second;
			}

		}
		else {
			if (i != 0 && v[i].first == v[i - 1].first) {
				sum += v[i].second - v[i - 1].second;
			}
		}
	}

	cout << sum;

	return 0;
}