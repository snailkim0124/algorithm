#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	for (auto it : v) {
		cout << it << "\n";
	}

	return 0;
}