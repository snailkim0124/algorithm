#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int n, m;
int visited[105];
int arr[105]; // 보드판(1차원)

void bfs() { // bfs 방법 x는 현재 위치, y는 카운트

	queue<pair<int, int>> q;
	q.push({1,0}); // 1부터 시작, 0부터 카운트

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;

			if (nx == 100) {
				cnt++;
				cout << cnt;
				return;
			}
			else if (nx < 100) {
				while (1) {
					if (arr[nx] == 0) break;
					nx = arr[nx]; // 사다리 및 뱀을 통해 이동
				}

				if (!visited[nx]) {
					q.push({nx, cnt+1}); // 카운트
					visited[nx] = 1; //방문 처리
				}

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) { // 사다리
		int x, y;
		cin >> x >> y;
		arr[x] = y;
	}

	for (int i = 0; i < m; i++) { // 스네이크
		int u, v;
		cin >> u >> v;
		arr[u] = v;
	}

	bfs(); 

	return 0;
}