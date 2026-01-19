#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = n; ; i++) {
		int mask = 0;

		// 켜진 비트 세기
		int ti = i;
		for (; ti; ti >>= 1) {
			if (ti & 1) mask++;
		}

		if (mask <= k) {
			cout << i - n << "\n";
			break;
		}
	}

	return 0;
}