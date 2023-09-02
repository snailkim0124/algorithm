#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int n, m;
int res[10];
int arr[10];
int check[10];

void dfs(int depth, int idx) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = idx; i < n; i++) {
			if (check[i] == 0) {
				res[depth] = arr[i];
				check[i] = 1;
				dfs(depth + 1, i + 1);
				check[i] = 0;
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}