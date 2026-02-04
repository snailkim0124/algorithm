#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n;
int arr[25][25], tmp[25][25];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res = INF;

void change(int y, int x) {
	arr[y][x] = !arr[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		arr[ny][nx] = !arr[ny][nx];
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp[i][j];
		}
	}

	// 맨 첫줄이 정해지면 밑의 줄은 그리디로 처리
	for (int mask = 0; mask < (1 << n); mask++) {
		memcpy(arr, tmp, sizeof(tmp));
		int cnt = 0;

		// 첫 줄처리
		for (int j = 0; j < n; j++) {
			if ((mask & (1 << j)) == 0) {
				change(0, j);
				cnt++;
			}
		}


		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(arr[i - 1][j] == 1) {
					change(i, j);
					cnt++;
				}
			}
		}

		bool flag = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					flag = false;
					break;
				}
			}
			if (!flag) break;
		}

		if (flag) {
			res = min(res, cnt);
		}
	}
	
	if (res == INF) cout << -1 << "\n";
	else cout << res << "\n";

	return 0;
}