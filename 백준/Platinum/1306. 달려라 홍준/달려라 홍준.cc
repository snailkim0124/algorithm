#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m;
ll arr[1000005];
deque<ll> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// 탐색 범위
	ll sz = 2 * m - 1;

	for (int i = 0; i < n; i++) {
		while (!dq.empty() && arr[dq.back()] < arr[i]) {
			dq.pop_back();
		}

		dq.push_back(i);

		// 윈도우 벗어난 값 제거
		if (dq.front() <= i - sz) {
			dq.pop_front();
		}

		if (i >= sz - 1) {
			cout << arr[dq.front()] << " ";
		}
	}
	cout << "\n";


	return 0;
}