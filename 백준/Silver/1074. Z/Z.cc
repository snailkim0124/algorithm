#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int n, r, c;
int ans;

void dfs(int y, int x, int size) {
	if (y == r && x == c) {
		cout << ans;
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x) {
		dfs(y, x, size / 2);
		dfs(y, x + size / 2, size / 2);
		dfs(y + size / 2, x, size / 2);
		dfs(y + size / 2, x + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> r >> c;
	dfs(0, 0, pow(2, n));
	return 0;
}