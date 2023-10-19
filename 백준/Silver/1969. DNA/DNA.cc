#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
string v[1005];
string ans;
int alpha[4];
const int INF = 987654321;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < m; i++) {
		memset(alpha, 0, sizeof(alpha));
		int mx = 0;
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 'A') {
				alpha[0]++;
			}
			else if (v[j][i] == 'C') {
				alpha[1]++;
			}
			else if (v[j][i] == 'G') {
				alpha[2]++;
			}
			else if (v[j][i] == 'T') {
				alpha[3]++;
			}
		}

		for (int j = 0; j < 4; j++) {
			if (mx < alpha[j]) {
				mx = alpha[j];
				idx = j;
			}
		}

		if (idx == 0) {
			ans += 'A';
		}
		else if (idx == 1) {
			ans += 'C';
		}
		else if (idx == 2) {
			ans += 'G';
		}
		else if (idx == 3) {
			ans += 'T';
		}
		cnt += n - mx;
	}

	cout << ans << "\n";
	cout << cnt;
	return 0;
}