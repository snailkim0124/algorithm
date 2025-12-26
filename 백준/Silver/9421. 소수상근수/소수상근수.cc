#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int prime[1000005];
vector<int> v, ans;

int go(int num) {
	string s = to_string(num);
	int res = 0;
	for (auto it : s) {
		res += (it - '0') * (it - '0');
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i * i <= n; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			prime[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (prime[i]) v.push_back(i);
	}

	for (auto p : v) {
		set<int> s;
		int now = p;
		s.insert(now);

		while (1) {
			int next = go(now);
			if (next == 1) {
				ans.push_back(p);
				break;
			}
			if (s.count(next)) {
				break;
			}
			s.insert(next);
			now = next;
		}
	}

	for (auto it : ans) {
		cout << it << "\n";
	}
	
	return 0;
}