#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int a[105];
int m;
int b[105];
int dp[105][105];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int aidx = 0;
	int bidx = 0;
	while (aidx < n && bidx < m) {
		int tmp = 0;
		int atmp, btmp;
		for (int i = aidx; i < n; i++) {
			for (int j = bidx; j < m; j++) {
				if (a[i] == b[j]) {
					if (tmp < a[i]) {
						atmp = i;
						btmp = j;
						tmp = a[i];
					}
				}
			}
		}
		if (tmp) {
			ans.push_back(tmp);
			aidx = atmp + 1;
			bidx = btmp + 1;
		}
		else break;
	}

	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it << " ";
	}

	return 0;
}