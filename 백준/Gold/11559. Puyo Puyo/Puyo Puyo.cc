#include <bits/stdc++.h>

using namespace std;

char arr[15][10];
int visited[15][10];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int cnt;
vector<pair<int, int>> boom;
int res = 0;

void falling() {
	/*cout << "\n";
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";*/

	queue<char> q;
	// 세로줄 탐색
	for (int i = 0; i < 6; i++) {
		// 위에서 부터 탐색
		for (int j = 11; j >= 0; j--) {
			if (arr[j][i] != '.') q.push(arr[j][i]);
		}
		for (int j = 11; j >= 0; j--) {
			if (q.empty()) {
				arr[j][i] = '.';
				continue;
			}
			arr[j][i] = q.front();
			q.pop();
		}
	}
}

void bfs(int Y, int X) {
	boom.clear(); // 터질 목록 초기화
	cnt = 1; // 카운트 초기화
	queue<pair<int, int>> q;

	boom.push_back({ Y, X });
	q.push({ Y, X });
	visited[Y][X] = 1;
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12 || arr[ny][nx] == '.' || visited[ny][nx]) continue;
			// 이전 거랑 같을 때
			if (arr[y][x] == arr[ny][nx]) {
				visited[ny][nx] = 1;
				cnt++;
				q.push({ ny, nx });
				boom.push_back({ ny, nx });
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		bool flag = false;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] != '.' && !visited[i][j]) {
					bfs(i, j);

					// 터지기
					if (cnt >= 4) {
						for (auto it : boom) {
							arr[it.first][it.second] = '.';
						}
						flag = true;
					}
				}
			}
		}

		if (flag) res++;
		else break; // 터질게 없음

		falling(); // 위에 있는 블록 떨어뜨리기
	}

	cout << res;

	return 0;
}