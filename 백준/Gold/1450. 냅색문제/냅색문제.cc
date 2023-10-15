#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, c;
ll arr[35];
ll res;
vector<ll> v, v2;

void knapsack(int here, int end, vector<ll>& v, int sum) {
	if (sum > c) return;
	if (here > end) {
		v.push_back(sum);
		return;
	}

	knapsack(here + 1, end, v, sum + arr[here]);
	knapsack(here + 1, end, v, sum);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	knapsack(0, n / 2 - 1, v, 0); // 0 ~ n/2까지
	knapsack(n / 2, n - 1, v2, 0); // n/2 ~ n-1 까지
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	for (auto it : v) {
		// (c - it) 이하인 수의 개수를 반환
		if (c - it >= 0) res += ((int)(upper_bound(v2.begin(), v2.end(), c - it) - v2.begin()));
	}

	cout << res;

	return 0;
}