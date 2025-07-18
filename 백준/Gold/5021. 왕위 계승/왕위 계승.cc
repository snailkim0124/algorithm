#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
string king;
map<string, vector<string>> family; // 가족
map<string, pair<int, double>> deg; // 이름, { 부모 수, 피}
string res;
double mx = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	// 유토피아 세운 사람
	cin >> king;
	deg[king] = { 0, 1 };

	// 가족 정보
	for (int i = 0; i < n; i++) {
		string a, b, c;
		cin >> a >> b >> c;
		
		// 부모 추가
		if (deg.find(b) == deg.end()) deg[b] = { 0 ,0 };
		if (deg.find(c) == deg.end()) deg[c] = { 0, 0 };
		deg[a] = { 2, 0 };

		family[b].push_back(a);
		family[c].push_back(a);
	}

	queue<string> q;
	for (auto it : deg) {
		// 부모가 0
		if (it.second.first == 0) q.push(it.first);
	}

	while (!q.empty()) {
		string parent = q.front();
		q.pop();

		// 자식 살펴보기
		for (auto child : family[parent]) {
			deg[child].first--;
			deg[child].second += deg[parent].second; // 부모 피 더하기

			if (deg[child].first == 0) {
				q.push(child);
				deg[child].second /= 2.0;
			}
		}
	}


	// 계승 받고 싶은 사람
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (mx < deg[s].second) {
			mx = deg[s].second;
			res = s;
		}
	}

	cout << res;

	return 0;
}