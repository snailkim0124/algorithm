#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r, c;
char arr[260][260];
int visited[260][260];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int wolf, sheep;
int sumwolf, sumsheep;

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
		if (!visited[ny][nx] && arr[ny][nx] != '#') {
			if (arr[ny][nx] == 'v') {
				wolf++;
			}
			else if (arr[ny][nx] == 'o') {
				sheep++;
			}
			dfs(ny, nx);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!visited[i][j] && arr[i][j] != '#') {
				wolf = 0;
				sheep = 0;
				if (arr[i][j] == 'v') {
					wolf++;
				}
				else if (arr[i][j] == 'o') {
					sheep++;
				}
				dfs(i, j);
				if (sheep > wolf) {
					sumsheep += sheep;
				}
				else {
					sumwolf += wolf;
				}
			}
		}
	}

	cout << sumsheep << " " << sumwolf;

	return 0;
}