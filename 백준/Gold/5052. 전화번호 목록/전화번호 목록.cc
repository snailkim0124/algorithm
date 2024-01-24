#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 10 + 5;
bool check[MX];
int nxt[MX][26];

void init() {
	fill(&nxt[0][0], &nxt[0][0] + MX * 26, -1);
	memset(check, 0, sizeof(check));
	unused = ROOT + 1;
}

int c2i(char c) {
	return c - 'A';
}

int insert(string& s) {
	int cur = ROOT;
	for (auto c : s) {
		if (nxt[cur][c2i(c)] == -1) {
			nxt[cur][c2i(c)] = unused++;
		}
		cur = nxt[cur][c2i(c)];
		if (check[cur]) return 0;
	}
	if (cur != unused - 1) return 0;
	return check[cur] = true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		init();
		bool check = false;
		cin >> n;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			// 접두어를 못찾은 경우
			if (!insert(s)) {
				check = true;
			}
		}

		if (!check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}