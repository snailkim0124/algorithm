#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int tt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> tt;
	while (tt--) {
		deque<char> dq;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (dq.empty() || dq.front() >= c) dq.push_front(c);
			else dq.push_back(c);
		}

		while (!dq.empty()) {
			cout << dq.front();
			dq.pop_front();
		}

		cout << "\n";
	}
	

	return 0;
}