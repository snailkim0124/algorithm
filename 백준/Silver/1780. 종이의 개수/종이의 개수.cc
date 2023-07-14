#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
int n;
int a[3000][3000];
int mone, pone, zero;

void dfs(int y, int x, int size) {

	int first = a[y][x];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (first != a[i][j]) {
				dfs(y, x, size / 3);
				dfs(y, x + size / 3, size / 3);
				dfs(y + size / 3, x, size / 3);
				dfs(y, x + size / 3 + size/3, size / 3);
				dfs(y + size / 3 + size/3, x, size / 3);
				dfs(y + size/3, x + size / 3 + size / 3, size / 3);
				dfs(y + size / 3 + size / 3, x + size/3, size / 3);
				dfs(y + size / 3, x + size / 3, size / 3);
				dfs(y + size / 3 + size/3, x + size / 3 + size/3, size / 3);
				return;
			}
		}
	}

	if (first == 1) pone++;
	else if (first == -1) mone++;
	else zero++;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0, n);

	cout << mone << "\n" << zero << "\n" << pone;
	return 0;
}