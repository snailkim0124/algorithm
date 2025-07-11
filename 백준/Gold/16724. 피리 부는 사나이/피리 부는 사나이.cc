#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
char arr[1005][1005];
int visited[1005][1005];
int cnt = 1;
set<int> st;

void print_arr() {
	cout << "========================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "========================\n";
}

int dfs(int y, int x) {
	if (visited[y][x]) return visited[y][x];

	visited[y][x] = cnt;

	if (arr[y][x] == 'U') {
		return visited[y][x] = dfs(y - 1, x);
	}
	else if (arr[y][x] == 'D') {
		return visited[y][x] = dfs(y + 1, x);
	}
	else if (arr[y][x] == 'L') {
		return visited[y][x] = dfs(y, x - 1);
	}
	else if (arr[y][x] == 'R') {
		return visited[y][x] = dfs(y, x + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	// 싸이클 만들어지는 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			st.insert(visited[i][j]);
		}
	}

	cout << st.size();

	return 0;
}