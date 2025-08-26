#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct ROOM {
	char c;
	int money;
	vector<int> adj;
}ROOM;

ROOM room[1005];
int visited[1005];
int n;
bool ans;

void dfs(int now, int money) {
	visited[now] = 1;

	if (room[now].c == 'E') {
		for (auto next : room[now].adj) {
			if (!visited[next]) {
				dfs(next, money);
			}
		}
	}
	else if (room[now].c == 'L') {
		money = max(money, room[now].money);
		for (auto next : room[now].adj) {
			if (!visited[next]) {
				dfs(next, money);
			}
		}
	}
	else if (room[now].c == 'T') {
		if (money < room[now].money) {
			visited[now] = 0;
			return;
		}

		for (auto next : room[now].adj) {
			if (!visited[next]) {
				dfs(next, money - room[now].money);
			}
		}
	}

	if (now == n) {
		ans = true;
		return;
	}

	visited[now] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		// 초기화
		for (int i = 1; i <= n; i++) {
			room[i].c = 0;
			room[i].money = 0;
			room[i].adj.clear();
			visited[i] = 0;
		}
		ans = false;

		cin >> n;
		if (!n) break;

		for (int i = 1; i <= n; i++) {
			cin >> room[i].c >> room[i].money;
			while (1) {
				int num;
				cin >> num;
				if (!num) break;
				room[i].adj.push_back(num);
			}
		}

		dfs(1, 0);

		cout << (ans ? "Yes\n" : "No\n");
	}
	
	
	return 0;
}