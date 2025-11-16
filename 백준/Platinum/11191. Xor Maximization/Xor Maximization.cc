#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
vector<ll> basis(64); // 기저

void insert(ll num) {
	for (int i = 63; i >= 0; i--) {
		if (!((num >> i) & 1)) continue; // i번째 비트가 0이면 통과

		if (basis[i] == 0) {
			basis[i] = num;
			return;
		}

		num ^= basis[i]; // i번째 비트를 0으로 만들기
	}
}

ll query() {
	ll mx = 0;
	for (int i = 63; i >= 0; i--) {
		mx = max(mx, mx ^ basis[i]);
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	insert(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		insert(num);
	}

	cout << query() << "\n";
	
	return 0;
}