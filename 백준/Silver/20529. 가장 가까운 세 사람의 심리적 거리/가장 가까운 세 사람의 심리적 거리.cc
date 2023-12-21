#include <bits/stdc++.h>

using namespace std;

int t;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int mn = 987654321;
		int n;
		cin >> n;
		vector<string> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		if (n > 32) {
			cout << 0 << "\n";
			continue;
		}

		// 조합
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					int cnt = 0;
					for (int l = 0; l < 4; l++) {
						if (v[i][l] != v[j][l]) cnt++;
						if (v[j][l] != v[k][l]) cnt++;
						if (v[k][l] != v[i][l]) cnt++;
					}
					mn = min(mn, cnt);
				}
			}
		}

		cout << mn << "\n";
	}
	
	return 0;
}