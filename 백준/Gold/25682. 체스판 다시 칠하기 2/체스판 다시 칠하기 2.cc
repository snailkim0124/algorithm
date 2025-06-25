#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, k;
char arr[2005][2005];
int white[2005][2005], black[2005][2005];
int mn = 987654321;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	// B = 1, W = 0

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((i + j) % 2 == 0) {
				if (arr[i][j] == 'B') white[i][j]++;
				else if(arr[i][j] == 'W') black[i][j]++;
			}
			else {
				if (arr[i][j] == 'W') white[i][j]++;
				else if(arr[i][j] == 'B') black[i][j]++;
			}

			white[i][j] += white[i][j - 1] + white[i - 1][j] - white[i - 1][j - 1];
			black[i][j] += black[i][j - 1] + black[i - 1][j] - black[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= m - k + 1; j++) {
			int tmp_w = white[i + k - 1][j + k - 1] - white[i + k - 1][j - 1] - white[i - 1][j + k - 1] + white[i - 1][j - 1];
			int tmp_b = black[i + k - 1][j + k - 1] - black[i + k - 1][j - 1] - black[i - 1][j + k - 1] + black[i - 1][j - 1];
			mn = min(mn, min(tmp_b, tmp_w));
		}
	}

	cout << mn << "\n";
	
	return 0;
}