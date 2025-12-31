#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

void solve() {
	ll n;
	cin >> n;

	// -1이 되는 케이스는 없는듯? -> 수학적으로 한번에 해결할 방법을 찾아야 됨
	// 9를 이용하기
	cout << 999999999 * n << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}


	return 0;
}