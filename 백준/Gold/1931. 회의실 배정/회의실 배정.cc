#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n;
int start, _end;
int res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> start >> _end;
		v.push_back({ _end, start });
	}

	sort(v.begin(), v.end());
	start == v[0].second;
	_end = v[0].first;

	for (int i = 1; i < n; i++) {
		if (v[i].second < _end) continue;
		start = v[i].second;
		_end = v[i].first;
		res++;
	}

	cout << res + 1;

	return 0;
}