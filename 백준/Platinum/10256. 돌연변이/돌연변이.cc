#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int stoidx(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	return 0;
}

struct Node {
	bool end;
	int nxt[4];
	int fail;
	Node() : end(false) {
		fill(nxt, nxt + 4, 0);
	}
};

vector<Node> trie;

void insert(const string& s) {
	int now = 0;

	for (char c : s) {
		int idx = stoidx(c);
		if (!trie[now].nxt[idx]) {
			trie[now].nxt[idx] = trie.size();
			trie.push_back(Node());
		}
		now = trie[now].nxt[idx];
	}
	trie[now].end = true;
}

// 실패 함수
void failure() {
	queue<int> q;

	for (int i = 0; i < 4; i++) {
		if (trie[0].nxt[i]) {
			trie[trie[0].nxt[i]].fail = 0;
			q.push(trie[0].nxt[i]);
		}
	}

	// 트라이에 존재하는 가장 긴 접미사를 fail에 저장
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtNode = trie[now].nxt[i];

			if (nxtNode) {
				trie[nxtNode].fail = trie[trie[now].fail].nxt[i];
				if (trie[trie[nxtNode].fail].end) {
					trie[nxtNode].end = true;
				}
				q.push(nxtNode);
			}
			else {
				trie[now].nxt[i] = trie[trie[now].fail].nxt[i];
			}
		}


	}
}


int check(const string& p) {
	int now = 0;
	int cnt = 0;

	for (char c : p) {
		int idx = stoidx(c);
		now = trie[now].nxt[idx];

		if (trie[now].end) cnt++;
	}

	return cnt;
}

void solve() {
	trie.clear();
	trie.push_back(Node()); // 루트 노드 생성

	int n, m;
	cin >> n >> m;
	string s, marker;
	cin >> s >> marker;

	// 총 나올 수 있는 개수 = m * (m - 1) / 2
	set<string> v;

	v.insert(marker);
	for (int i = 0; i <= m; i++) {
		for (int j = i + 2; j <= m; j++) {
			reverse(marker.begin() + i, marker.begin() + j);
			v.insert(marker);
			reverse(marker.begin() + i, marker.begin() + j);
		}
	}

	for (auto ms : v) {
		insert(ms);
	}

	failure();

	cout << check(s) << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}


	return 0;
}