#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		vector<int> v;
		priority_queue<int, vector<int>, greater<int>> min_pq;
		priority_queue<int> max_pq;
		int m;
		cin >> m;

		for (int i = 1; i <= m; i++) {
			int num;
			cin >> num;
			if (i % 2 == 1) {
				max_pq.push(num);
				if (!max_pq.empty() && !min_pq.empty()) {
					if (max_pq.top() > min_pq.top()) {
						min_pq.push(max_pq.top());
						max_pq.pop();
						max_pq.push(min_pq.top());
						min_pq.pop();
					}
				}
				v.push_back(max_pq.top());
			}
			else min_pq.push(num);
		}

		cout << v.size() << "\n";
		// int cnt = 0;
		for (auto it : v) {
			// if (cnt % 10 == 0) cout << "\n";
			cout << it << " ";
			// cnt++;
		}
	}
	

	return 0;
}