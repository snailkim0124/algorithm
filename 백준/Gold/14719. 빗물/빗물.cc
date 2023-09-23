#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

int h, w;
int a[505];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < w - 1; i++) {
		int left = 0;
		int right = 0;
		for (int j = 0; j < i; j++) { // 왼쪽 최대
			left = max(left, a[j]);
		}
		for (int j = w - 1; j > i; j--) { // 오른쪽 최대
			right = max(right, a[j]);
		}
		int Min = min(left, right); // 왼쪽, 오른쪽 최소
		if (Min - a[i] >= 0) {
			ans += Min - a[i];
		}
	}

	cout << ans;
	return 0;
}