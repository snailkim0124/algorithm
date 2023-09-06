#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
int n, m;
vector<int> v;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int left = 0;
	int right = v[v.size() - 1];

	while (left <= right) {
		ll sum = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) sum += v[i] - mid;
		}
		if (sum < m) {
			right = mid - 1;
		}
		else {
			res = mid;
			left = mid + 1;
		}
	}
	cout << res;
	return 0;
}