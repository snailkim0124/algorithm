#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

int n, m;
char arr[605][605];
int visited[605][605];
int starti, startj;
int cnt;
int dy[4] = { -1, 0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'I') {
				starti = i;
				startj = j;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({ starti, startj });
	visited[starti][startj] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (arr[nx][ny] == 'X' || visited[nx][ny]) continue;
			if (arr[nx][ny] == 'P') {
				cnt++;
			}
			visited[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	if (cnt == 0) cout << "TT";
	else cout << cnt;
	
	return 0;
}