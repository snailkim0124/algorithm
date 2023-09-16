#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <tuple>
#include <memory.h>

using namespace std;

int n;
vector<pair<int, int>> v;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, timing;
		cin >> start >> timing;
		v.push_back({ start, timing });
	}
	
	sort(v.begin(), v.end());

	res += v[0].first + v[0].second;

	for (int i = 1; i < n; i++) {
		res = max(res, v[i].first);
		res += v[i].second;
	}

	cout << res;
	
	return 0;
}