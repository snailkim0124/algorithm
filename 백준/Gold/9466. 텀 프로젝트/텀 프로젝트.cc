#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;
int arr[100005];
int visited[100005];
int finished[100005];
int cnt;

void dfs(int here) {
	visited[here] = 1;
	int there = arr[here];

	if (!visited[there]) {
		dfs(there);
	}
	else if (!finished[there]) {
		// 연결되었던 정점 방문
		for (int cur = there; cur != here; cur = arr[cur]) {
			cnt++;
		}
		cnt++;
	}

	finished[here] = 1; // 끝남
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));
		memset(finished, 0, sizeof(finished));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
			}
		}

		cout << n - cnt << "\n";
	}

	return 0;
}