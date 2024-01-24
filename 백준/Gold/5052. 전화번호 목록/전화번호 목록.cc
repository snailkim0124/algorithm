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
		bool check = false;
		cin >> n;
		multiset<string> mt;
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			string tmp;
			for (int j = 0; j < v[i].size(); j++) {
				tmp += v[i][j];
				// 접두어를 못찾은 경우
				if (mt.find(tmp) != mt.end()) {
					check = true;
					break;
				}
			}
			if (check) break;
			mt.insert(v[i]);
		}

		if (!check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}