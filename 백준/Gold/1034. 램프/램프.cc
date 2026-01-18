#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
string arr[55];
map<string, int> mp;
int k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}
	cin >> k;

	int mx = 0;
	for (auto [s, score] : mp) {
		int zero = 0;
		for (auto it : s) {
			if (it == '0') zero++;
		}

		if (zero > k) continue;

		// 남는 횟수가 짝수여야 됨
		if ((k - zero) % 2 == 0) {
			mx = max(mx, score);
		}
	}

	cout << mx << "\n";



	
	return 0;
}