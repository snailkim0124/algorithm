#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> v;
vector<int> lis, idx, res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end()); // a 부분 기준으로 오름차순 정렬

	for (int i = 0; i < n; i++) {
		if (idx.empty() || lis.back() < v[i].second) {
			idx.push_back(lis.size());
			lis.push_back(v[i].second);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), v[i].second); // LIS 방식 문제
			*it = v[i].second;
			idx.push_back(it - lis.begin());
		}
	}

	cout << n - lis.size() << "\n";

	int tmp = lis.size() - 1;
	for (int i = idx.size() - 1; i >= 0; i--) {
		if (tmp == idx[i]) tmp--;
		else res.push_back(v[i].first);
	}

	reverse(res.begin(), res.end());

	for (auto it : res) {
		cout << it << "\n";
	}

	return 0;
}