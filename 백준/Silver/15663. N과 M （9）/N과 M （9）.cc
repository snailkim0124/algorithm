#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <tuple>

using namespace std;

int n, m;
int res[10];
int arr[10];
int check[10];

void dfs(int depth) {
	int num = 0;
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
	}

	else {
		for (int i = 0; i < n; i++) {
			if (check[i] == 0) {
				if (num == arr[i]) continue;
				res[depth] = arr[i];
				num = res[depth];
				check[i] = 1;
				dfs(depth + 1);
				check[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	dfs(0);
	return 0;
}