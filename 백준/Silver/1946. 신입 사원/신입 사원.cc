#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int cnt = 1;
		cin >> n;
		vector<pair<int, int>> v(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end());

		int mn = v[0].second;

		for (int i = 1; i < n; i++) {
			if (mn > v[i].second) {
				mn = v[i].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}