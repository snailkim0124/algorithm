#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		string a, b;
		vector<int> v1, v2;
		int res = 0;

		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << -1 << "\n";
			continue;
		}

		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'a') v1.push_back(i);
		}

		for (int i = 0; i < b.size(); i++) {
			if (b[i] == 'a') v2.push_back(i);
		}

		for (int i = 0; i < v1.size(); i++) {
			res += abs(v1[i] - v2[i]);
		}

		cout << res << "\n";
	}

	return 0;
}