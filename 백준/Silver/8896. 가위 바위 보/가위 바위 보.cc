#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;
string robot[15];
int check[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	cin.ignore();

	while (t--) {
		memset(check, 0, sizeof(check)); // 살아있는지?
		for (int i = 0; i < 15; i++) {
			robot[i].clear();
		}

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> robot[i];
			check[i] = 1;
		}

		int round = robot[1].size();
		for (int i = 0; i < round; i++) {
			int s = 0, r = 0, p = 0;

			for (int j = 1; j <= n; j++) {
				if (!check[j]) continue;
				if (robot[j][i] == 'R') r++;
				else if (robot[j][i] == 'S') s++;
				else if (robot[j][i] == 'P') p++;
			}

			if (p && s && r) continue;
			if (!p && !s && r) continue;
			if (p && !s && !r) continue;
			if (!p && s && !r) continue;
			else if (!p) {
				for (int j = 1; j <= n; j++) {
					if (robot[j][i] == 'S') check[j] = 0;
				}
			}
			else if (!s) {
				for (int j = 1; j <= n; j++) {
					if (robot[j][i] == 'R') check[j] = 0;
				}
			}
			else if (!r) {
				for (int j = 1; j <= n; j++) {
					if (robot[j][i] == 'P') check[j] = 0;
				}
			}
		}

		int cnt = 0, win = -1;
		for (int i = 1; i <= n; i++) {
			if (check[i]) {
				cnt++;
				win = i;
			}
		}

		if (cnt == 1) cout << win << "\n";
		else cout << 0 << "\n";
	}
	
	return 0;
}