#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[105][105];
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	while (n--) {
		int startx, starty, endx, endy;
		cin >> startx >> starty >> endx >> endy;
		for (int i = startx; i <= endx; i++) {
			for (int j = starty; j <= endy; j++) {
				arr[i][j]++;
			}
		}
	}

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] > m) cnt++;
		}
	}
	
	cout << cnt;

	return 0;
}