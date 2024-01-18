#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
vector<pair<tuple<int, int, int>, int>> v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int num, a, b, c;
		cin >> num >> a >> b >> c;
		v.push_back({ { a,b,c }, num });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (v[i].second == k) {
			if (i != 0 && v[i].first == v[i - 1].first) {
				cout << i;
			}
			else {
				cout << i + 1;
			}
			break;
		}
	}
	
	return 0;
}