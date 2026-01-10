#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k, m;
int arr[100005];
int dp[32][100005];
int nxt[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= k; i++) {
		cin >> dp[0][i];
	}

	for (int i = 1; i < 30; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}

	for (int i = 0; i < n; i++) {
		int now = arr[i];
		for (int j = 0; j < 30; j++) {
			if ((m - 1) & (1 << j)) {
				now = dp[j][now];
			}
		}
		cout << now << " ";
	}
	cout << "\n";


	return 0;
}