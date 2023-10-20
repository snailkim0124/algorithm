#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll sum;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	while (m--) {
		ll a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;

	return 0;
}