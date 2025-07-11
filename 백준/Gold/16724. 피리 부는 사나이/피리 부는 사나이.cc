#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
char arr[1005][1005];
pii parent[1005][1005];
int cnt = 0;

pii findParent(pii a) {
	if (a == parent[a.first][a.second]) return a;
	else return parent[a.first][a.second] = findParent(parent[a.first][a.second]);
}

void unionParent(pii a, pii b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[b.first][b.second] = a;
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
	
	// 유니온-파인드
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			parent[i][j] = { i, j };
		}
	}

	// 싸이클 만들어지는 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pii np;
			if (arr[i][j] == 'U') np = findParent({ i - 1, j });
			else if (arr[i][j] == 'D') np = findParent({ i + 1, j });
			else if (arr[i][j] == 'L') np = findParent({ i, j - 1 });
			else if (arr[i][j] == 'R') np = findParent({ i, j + 1 });

			if (np != make_pair(i, j)) {
				unionParent(np, { i, j }); // 부모 같도록 하기
				cnt++;
			}
		}
	}

	cout << n * m - cnt;

	return 0;
}