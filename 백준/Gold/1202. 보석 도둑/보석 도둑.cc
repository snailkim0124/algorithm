#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;

ll n, k, res;
priority_queue<ll> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	vector<pair<ll, ll>> jewel(n);
	vector<ll> weight(k);

	for (int i = 0; i < n; i++) {
		cin >> jewel[i].first >> jewel[i].second; // 무게, 가격
	}
	for (int i = 0; i < k; i++) {
		cin >> weight[i];
	}
	sort(jewel.begin(), jewel.end());
	sort(weight.begin(), weight.end());

	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && jewel[j].first <= weight[i]) {
			pq.push(jewel[j].second);
			j++;
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
	return 0;
}