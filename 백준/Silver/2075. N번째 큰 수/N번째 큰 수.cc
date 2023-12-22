#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n * n; i++) {
		ll num;
		cin >> num;
		pq.push(num);
		if (pq.size() > n) {
			pq.pop();
		}
	}

	cout << pq.top();
	

	return 0;
}