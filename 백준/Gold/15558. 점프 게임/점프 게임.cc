#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;
char arr[2][100005];
int visited[2][100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	queue<tii> q;
	q.push({ 0,0,0 });
	visited[0][0] = 1;

	while (!q.empty()) {
		auto [y, x, cnt] = q.front();
		q.pop();

		if (x < cnt) continue;

		if (x == n) {
			cout << 1 << "\n";
			exit(0);
		}

		// 한칸 앞
		if (arr[y][x + 1] == '1' && !visited[y][x + 1]) {
			visited[y][x + 1] = 1;
			q.push({ y, x + 1, cnt + 1 });
		}

		// 한칸뒤
		if (x - 1 >= cnt && arr[y][x - 1] == '1' && !visited[y][x - 1]) {
			visited[y][x - 1] = 1;
			q.push({ y, x - 1, cnt + 1 });
		}

		// 점프
		if (x + k >= n) {
			cout << 1 << "\n";
			exit(0);
		}
		else if (arr[!y][x + k] == '1' && !visited[!y][x + k]) {
			visited[!y][x + k] = 1;
			q.push({ !y, x + k, cnt + 1 });
		}
	}

	cout << 0 << "\n";
	
	return 0;
}