#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct Node {
	bool end;
	int nxt[26];
	int fail;
	Node() : end(false) {
		fill(nxt, nxt + 26, 0);
	}
};

vector<Node> trie;

void insert(const string& s) {
	int now = 0;

	for (char c : s) {
		int idx = c - 'a';
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

	for (int i = 0; i < 26; i++) {
		if (trie[0].nxt[i]) {
			trie[trie[0].nxt[i]].fail = 0;
			q.push(trie[0].nxt[i]);
		}
	}

	// 트라이에 존재하는 가장 긴 접미사를 fail에 저장
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 26; i++) {
			int nxtNode = trie[now].nxt[i];

			if (nxtNode) {
				int f = trie[now].fail;

				while (f != 0 && !trie[f].nxt[i]) {
					f = trie[f].fail;
				}

				if (trie[f].nxt[i]) {
					f = trie[f].nxt[i];
				}

				trie[nxtNode].fail = f;

				if (trie[f].end) {
					trie[nxtNode].end = true;
				}

				q.push(nxtNode);
			}
		}


	}
}

bool check(const string& p) {
	int now = 0;

	for (char c : p) {
		int idx = c - 'a';
		

		while (now != 0 && !trie[now].nxt[idx]) {
			now = trie[now].fail;
		}

		if (trie[now].nxt[idx]) {
			now = trie[now].nxt[idx];
		}

		if (trie[now].end) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	trie.clear();
	trie.push_back(Node()); // 루트 노드 생성

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}

	failure();

	int q;
	cin >> q;
	while (q--) {
		string p;
		cin >> p;

		if (check(p)) {
			cout << "YES\n";
		}
		else cout << "NO\n";

	}



	return 0;
}