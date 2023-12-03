#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int w, h;
char arr[105][105];
int visited[105][105][4];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
bool check;
int startx, starty, endx, endy;
const int INF = 987654321;
queue<pair<pair<int, int>, pair<int, int>>> q;
int res = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&visited[0][0][0], &visited[0][0][0] + 105 * 105 * 4, INF);
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'C') {
				if (!check) {
					startx = i;
					starty = j;
					check = true;
				}
				else {
					endx = i;
					endy = j;
				}
			}
		}
	}


	for (int i = 0; i < 4; i++) {
		q.push({ { startx, starty}, {i, 0} }); // 4방향 초기화 및 넣기
		visited[startx][starty][i] = 0;
	}

	while (!q.empty()) {
		int herex = q.front().first.first;
		int herey = q.front().first.second;
		int herep = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (res < cnt) continue; // res보다 큰 개수면 뛰어넘기

		if (herex == endx && herey == endy) { // res 갱신
			res = min(res, cnt);
		}

		for (int i = 0; i < 4; i++) {
			if (i == (herep + 2) % 4) continue; // 레이저가 반대로 가는 것 불가능
			int nx = herex + dx[i];
			int ny = herey + dy[i];
			// int ncnt = cnt; // 다음 cnt

			if (nx < 0 || ny < 0 || nx >= h || ny >= w || arr[nx][ny] == '*') continue;
			//if (visited[nx][ny][i] && visited[nx][ny][i] != INF) continue; // 중복 방지
			//if (herep != i) ncnt++; // 방향을 틀 경우
			if (visited[nx][ny][i] > cnt && herep == i) { // 거울 설치 x
				visited[nx][ny][i] = cnt + 1;
				q.push({ { nx, ny}, {i, cnt } });
			}
			else if (visited[nx][ny][i] > cnt + 1) { // 거울 설치하는 경우
				visited[nx][ny][i] = cnt + 1;
				q.push({ { nx, ny}, {i, cnt + 1 } });
			}
		}
	}

	cout << res;

	return 0;
}
