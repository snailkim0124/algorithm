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
int visited[200004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	if (n == m) {
		cout << "0";
		exit(0);
	}
	visited[n] = 1;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		int now = q.front();
		int next[3] = { now - 1, now + 1, now * 2 };
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (0 <= next[i] && next[i] <= 200000) {
				if (visited[next[i]] == 0) {
					q.push(next[i]);
					visited[next[i]] = visited[now] + 1;
				}
			}
		}
	}

	cout << visited[m] - 1;
	return 0;
}