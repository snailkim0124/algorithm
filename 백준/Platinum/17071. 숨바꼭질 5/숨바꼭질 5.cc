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

int n, k;
int visited[2][500004];
int d = 1;
bool check;
int ans;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if (n == k) {
		cout << "0" << "\n";
		exit(0);
	}
	visited[0][n] = 1;
	queue<int> q;
	q.push(n);

	while (!q.empty()) {
		k += d;
		if (k > 500000) break;
		if (visited[d % 2][k]) {
			check = true;
			break;
		}
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int now = q.front();
			q.pop();
			int next[3] = { now - 1, now + 1, now * 2 };
			for (int j = 0; j < 3; j++) {
				if (next[j] < 0 || next[j] >500000) continue;
				if (visited[d % 2][next[j]]) continue;

				visited[d % 2][next[j]] = visited[(d + 1) % 2][now] + 1;

				if (next[j] == k) {
					check = true;
					break;
				}
				q.push(next[j]);
			}
			if (check == true) break;
		}
		if (check == true) break;
		d++;
	}
	
	if (check == true) cout << d;
	else cout << -1;
	return 0;
}