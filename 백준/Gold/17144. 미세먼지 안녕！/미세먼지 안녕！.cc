#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int r, c, t;
int arr[55][55];
int add[55][55];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
vector<pii> purifier;
pii up, down;

void spread_dust() {
	memset(add, 0, sizeof(add));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -1 && arr[i][j] != 0) {
				int cnt = 0;
				int dust = arr[i][j] / 5;
				int y = i;
				int x = j;

				for (int dir = 0; dir < 4; dir++) {
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					if (ny < 0 || nx < 0 || ny >= r || nx >= c || arr[ny][nx] == -1) continue;
					add[ny][nx] += dust;
					cnt++;
				}
				add[y][x] -= (dust * cnt);
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] += add[i][j];
		}
	}
}

void air_purifier() {
	// 위쪽
	for (int i = up.first - 1; i > 0; i--) {
		arr[i][0] = arr[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		arr[0][i] = arr[0][i + 1];
	}
	for (int i = 1; i <= up.first; i++) {
		arr[i - 1][c - 1] = arr[i][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		arr[up.first][i] = arr[up.first][i - 1];
	}
	arr[up.first][1] = 0;

	// 아래쪽
	for (int i = down.first + 1; i < r - 1; i++) {
		arr[i][0] = arr[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		arr[r - 1][i] = arr[r - 1][i + 1];
	}
	for (int i = r - 1; i >= down.first; i--) {
		arr[i][c - 1] = arr[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		arr[down.first][i] = arr[down.first][i - 1];
	}
	arr[down.first][1] = 0;

}

int count_dust() {
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -1) {
				sum += arr[i][j];
			}
		}
	}
	return sum;
}

void print_dust() {
	cout << "===============================\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "===============================\n";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				purifier.push_back({ i, j });
			}
		}
	}

	up = purifier[0];
	down = purifier[1];

	while(t--) {
		spread_dust();
		// cout << ">>> spread\n";
		// print_dust();

		air_purifier();
		// cout << ">>> purify\n";
		// print_dust();
	}
	cout << count_dust();

	return 0;
}