#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[1005][1005];
int k;
int x, y;
int cnt = 1;
int tmp;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int ansx, ansy;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> k;

	x = (n + 1) / 2;
	y = (n + 1) / 2;
	arr[y][x] = 1;

	int i = 2;

	while(1) {
		for (int j = 0; j < cnt; j++) {
			y += dy[tmp];
			x += dx[tmp];
			arr[y][x] = i++;
			if (i > n * n) break;
		}
		if (tmp == 1 || tmp == 3) cnt++;

		tmp = (tmp + 1) % 4;
		if (i > n * n) break;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
			if (arr[i][j] == k) {
				ansy = i;
				ansx = j;
			}
		}
		cout << "\n";
	}

	cout << ansy << " " << ansx;

	return 0;
}