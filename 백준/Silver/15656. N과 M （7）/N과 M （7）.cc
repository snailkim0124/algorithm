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

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == 0) {
				res[depth] = arr[i];
				dfs(depth + 1);
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
	dfs(0);
	return 0;
}