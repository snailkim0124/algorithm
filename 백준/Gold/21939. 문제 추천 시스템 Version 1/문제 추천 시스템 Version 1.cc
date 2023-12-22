#include <bits/stdc++.h>

using namespace std;

int n, m;
multiset<pair<int, int>> ms;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, l;
		cin >> p >> l; // 문제 번호, 난이도
		ms.insert({ l, p });
		mp[p] = l;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "recommend") {
			int x;
			cin >> x;
			if (x == -1) { // 최솟값 삭제
				cout << ms.begin()->second << "\n";
			}
			else if (x == 1) { // 최댓값 삭제
				auto it = ms.end();
				it--;
				cout << it->second << "\n";
			}
		}
		else if (cmd == "add") {
			int p, l;
			cin >> p >> l;
			ms.insert({ l, p });
			mp[p] = l;

		}
		else if (cmd == "solved") {
			int p;
			cin >> p;
			auto it = ms.find({ mp[p], p });
			ms.erase(it);
		}
	}

	return 0;
}