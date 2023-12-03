#include <bits/stdc++.h>

using namespace std;

int n;
int dist[25][25]; // 가중치
int visited[25][25];
const int INF = 987654321;
int sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&dist[0][0], &dist[0][0] + 25 * 25, INF); // 무한대 값으로 초기화

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dist[i][j];
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					cout << -1;
					exit(0);
				}
				if (i != k && j != k && dist[i][k] + dist[k][j] == dist[i][j]) {
					visited[i][j] = 1;
				}
			
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(!visited[i][j]) sum += dist[i][j];
		}
	}

	cout << sum/ 2;
}