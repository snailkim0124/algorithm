#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		if (min_pq.size() == max_pq.size()) max_pq.push(num);
		else min_pq.push(num);

		if (!max_pq.empty() && !min_pq.empty()) {
			if (max_pq.top() > min_pq.top()) {
				min_pq.push(max_pq.top());
				max_pq.pop();
				max_pq.push(min_pq.top());
				min_pq.pop();
			}
		}

		cout << max_pq.top() << "\n";
	}

	return 0;
}