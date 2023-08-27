#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

int n, m;
map<string, int> mp;

int cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			if (a.first < b.first) return 1;
			else return 0;
		}
		else {
			if (a.first.size() > b.first.size()) return 1;
			else return 0;
		}
	}
	else {
		if (a.second > b.second) return 1;
		else return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;
		if (word.size() >= m) {
			mp[word]++;
		}
	}

	vector<pair<string, int>> res(mp.begin(), mp.end());

	sort(res.begin(), res.end(), cmp);

	for (auto it : res) {
		cout << it.first << "\n";
	}

	return 0;
}