#include <bits/stdc++.h>

using namespace std;

int n;
int real_x, real_y;
int m;
int cnt;
int arr[105][105];
int visited[105];
queue<int> q;

void bfs(int start) { // bfs 방식
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) { // 모든 촌수
			if (arr[now][i] && !visited[i]) {
				visited[i] = visited[now] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> real_x >> real_y; // 시작, 끝
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	bfs(real_x); // 시작

	if (!visited[real_y]) cout << "-1"; // 끝에 있으면
	else cout << visited[real_y];

	return 0;
}