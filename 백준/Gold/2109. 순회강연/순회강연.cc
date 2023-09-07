#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
int n, res;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int p, d;
		cin >> p >> d;
		v.push_back({ d, p }); // 강연료, 기한
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++) {
		pq.push(v[i].second);
		if (pq.size() > v[i].first) pq.pop();
	}

	while (!pq.empty()) {
		res += pq.top();
		pq.pop();
	}

	cout << res;

	return 0;
}