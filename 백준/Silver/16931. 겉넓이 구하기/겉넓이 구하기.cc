#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[105][105];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res_next, res_mit;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	res_mit = n * m * 2;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				res_next += max(0, arr[i][j] - arr[ni][nj]);
			}
		}
	}

	cout << res_mit + res_next;
	
	return 0;
}