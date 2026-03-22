#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int res[10];
int visited[10];

void go(int depth, int prev) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (prev <= i) {
			res[depth] = i;
			go(depth + 1, i); // 다음 칸을 채우러 감
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	go(0, 0);
	
	return 0;
}