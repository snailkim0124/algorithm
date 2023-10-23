#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, string>> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].second >> v[i].first;
		}

		sort(v.begin(), v.end(), greater<>());

		cout << v[0].second << "\n";
	}

	return 0;
}