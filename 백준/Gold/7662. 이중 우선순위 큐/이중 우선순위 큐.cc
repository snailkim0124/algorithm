#include <bits/stdc++.h>

using namespace std;

int t;
int k;
int visited[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(visited, 0, sizeof(visited));
		priority_queue<pair<int, int>, vector<pair<int, int>>> mx_pq;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn_pq;
		int cnt = 0;
		cin >> k;

		while (k--) {
			char cmd;
			int n;
			cin >> cmd >> n;
			if (cmd == 'I') {
				mx_pq.push({ n, cnt }); // num, idx
				mn_pq.push({ n, cnt });
				visited[cnt++] = 1;
			}
			else if (cmd == 'D') {
				if (n == 1) { // 최댓값 삭제
					while (!mx_pq.empty() && !visited[mx_pq.top().second]) {
						mx_pq.pop();
					}

					if (mx_pq.empty()) continue;

					visited[mx_pq.top().second] = 0;
					mx_pq.pop();
				}
				else if (n == -1) { // 최솟값 삭제
					while (!mn_pq.empty() && !visited[mn_pq.top().second]) {
						mn_pq.pop();
					}

					if (mn_pq.empty()) continue;

					visited[mn_pq.top().second] = 0;
					mn_pq.pop();
				}
			}
		}	

		while (!mx_pq.empty() && !visited[mx_pq.top().second]) {
			mx_pq.pop();
		}
		while (!mn_pq.empty() && !visited[mn_pq.top().second]) {
			mn_pq.pop();
		}

		if (mn_pq.empty() || mx_pq.empty()) cout << "EMPTY\n";
		else cout << mx_pq.top().first << " " << mn_pq.top().first << "\n";

	}
	
	return 0;
}