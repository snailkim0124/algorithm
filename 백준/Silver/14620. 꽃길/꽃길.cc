#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[15][15];
int visited[15][15];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };
int res = 987654321;

int putflower(int y, int x) { // 꽃 놓기
	visited[y][x] = 1;
	int sum = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		sum += arr[ny][nx];
	}

	return sum;
}

bool check(int y, int x) {
	if (visited[y][x]) return 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[ny][nx]) return 0;
	}

	return 1;
}

void deleteflower(int y, int x) { // 꽃 없애기
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}

void flower(int cnt, int sum) {
	if (cnt == 3) { // 꽃 개수
		res = min(res, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(i, j)) {
				flower(cnt + 1, sum + putflower(i, j));
				deleteflower(i, j); // 원복
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	flower(0, 0);
	cout << res;

	return 0;
}