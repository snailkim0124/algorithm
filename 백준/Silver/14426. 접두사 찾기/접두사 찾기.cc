#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int n, m;
int ans;
const int ROOT = 1;
int unused = 2;
const int MX = 10000 * 500 + 5;
int nxt[MX][26];

int c2i(char c) {
	return c - 'A';
}

void insert(string& s) {
	int cur = ROOT;
	for (auto c : s) {
		if (nxt[cur][c2i(c)] == -1) {
			nxt[cur][c2i(c)] = unused++;
		}
		cur = nxt[cur][c2i(c)];
	}
}

bool find(string& s) {
	int cur = ROOT;
	for (auto c : s) {
		if (nxt[cur][c2i(c)] == -1) {
			return 0;
		}
		cur = nxt[cur][c2i(c)];
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&nxt[0][0], &nxt[0][0] + MX * 26, -1);

	cin >> n >> m;
	while (n--) {
		string s;
		cin >> s;
		insert(s);
	}

	while (m--) {
		string s;
		cin >> s;
		ans += find(s);
	}

	cout << ans;

	return 0;
}