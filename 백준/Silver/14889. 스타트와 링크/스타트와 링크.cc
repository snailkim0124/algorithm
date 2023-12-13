#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[25][25];
int visited[25];
int res = 987654321;

void startlink(int cnt, int here) {
	if (cnt == n / 2) {
		int start = 0;
		int link = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (visited[i] && visited[j]) { // 방문한 경우
					start += arr[i][j];
					start += arr[j][i];
				}
				if (!visited[i] && !visited[j]) { // 방문안한 경우
					link += arr[i][j];
					link += arr[j][i];
				}
			}
		}

		res = min(res, abs(start - link));
	}

	for (int i = here; i <= n; i++) {
		visited[i] = 1;
		startlink(cnt + 1, i + 1);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	
	startlink(0, 1);

	cout << res;

	return 0;
}