#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	while (m--) {
		int begin, end, mid;
		cin >> begin >> end >> mid;
		rotate(v.begin() + begin - 1, v.begin() + mid - 1, v.begin() + end);
	}

	for (auto it : v) {
		cout << it << " ";
	}

	return 0;
}