#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;
int cnt;
vector<int> v;

void go(int sum) {
	if (sum > n) return;
	if (sum == n) {
		cnt++;
		if (cnt == k) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
				if (i != v.size() - 1) cout << "+";
			}
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
		go(sum + i);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	go(0);

	if (cnt < k) cout << -1;
	
	return 0;
}