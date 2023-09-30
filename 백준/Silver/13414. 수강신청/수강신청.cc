#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int k, l;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k >> l;
	map<string, int> mp;
	vector<pair<string, int>> s;

	for (int i = 0; i < l; i++) {
		string num;
		cin >> num;
		mp[num] = i;
	}

	for (auto it : mp) {
		s.push_back(it);
	}

	sort(s.begin(), s.end(), cmp);

	int size = min((int)s.size(), k);

	for (int i = 0; i < size; i++) {
		cout << s[i].first << "\n";
	}
	return 0;
}