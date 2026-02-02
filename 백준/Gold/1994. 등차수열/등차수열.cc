#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int arr[2005];
int dp[2005][2005];
map<int, int> mp;
int mx = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}

	if (n <= 2) {
		cout << n << "\n";
		exit(0);
	}

	vector<int> v;
	// 공차 0 처리, 중복 제거
	for (auto it : mp) {
		mx = max(mx, it.second);
		v.push_back(it.first);
	}
	
	//for (auto it : v) {
	//	cout << it << " ";
	//}
	//cout << "\n";

	for (int i = 0; i < v.size(); i++) {
		int l = i - 1;
		int r = i + 1;

		while (0 <= l && r < v.size()) {
			int sum = v[l] + v[r];

			if (sum < 2 * v[i]) {
				r++;
			}
			else if (sum > 2 * v[i]) {
				l--;
			}
			else {
				int now = dp[l][i];
				if (now == 0) now = 2;
				dp[i][r] = now + 1;
				mx = max(mx, dp[i][r]);

				l--;
				r++;
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << dp[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << mx << "\n";

	return 0;
}