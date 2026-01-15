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
    map<char, Node*> nxt;
	Node* fail;
    Node() : end(false) {}
};

struct ahocorasick {
    Node* root;
    
	ahocorasick() {
		root = new Node();
		root->fail = root;
	}

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->nxt[c]) {
                node->nxt[c] = new Node();
            }
            node = node->nxt[c];
        }
        node->end = true;
    }

	// 실패 함수
	void failure() {
		queue<Node*> q;

		for (auto& [c, nxtNode] : root->nxt) {
			nxtNode->fail = root;
			q.push(nxtNode);
		}

		// 트라이에 존재하는 가장 긴 접미사를 fail에 저장
		while (!q.empty()) {
			auto now = q.front();
			q.pop();

			for (auto& [c, nxtNode] : now->nxt) {
				Node* f = now->fail;
				while (f != root && !f->nxt.count(c)) {
					f = f->fail;
				}

				if (f->nxt.count(c)) {
					nxtNode->fail = f->nxt[c];
				}
				else {
					nxtNode->fail = root;
				}

				nxtNode->end |= nxtNode->fail->end;

				q.push(nxtNode);
			}
		}
	}

	bool check(const string& p) {
		Node* node = root;
		for (char c : p) {
			while (node != root && !node->nxt.count(c)) {
				node = node->fail;
			}

			if (node->nxt.count(c)) {
				node = node->nxt[c];
			}

			if (node->end) return true;
		}

		return false;
	}
};

int n, q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ahocorasick T;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		T.insert(s);
	}

	T.failure();

	cin >> q;
	while (q--) {
		string p;
		cin >> p;

		if (T.check(p)) cout << "YES\n";
		else cout << "NO\n";
		
	}

	

	return 0;
}