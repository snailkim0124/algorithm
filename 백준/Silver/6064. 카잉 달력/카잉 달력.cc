#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int t;

tll ext_gcd(ll a, ll b) {
	if (b == 0) return { a, 1, 0 };
	auto [g, x1, y1] = ext_gcd(b, a % b);
	return { g, y1, x1 - (a / b) * y1 };
}

// 모듈러 역원
ll modinv(ll a, ll mod) {
	auto [g, x, y] = ext_gcd(a, mod);
	if (g != 1) return -1; // 역원 없음
	x %= mod;
	if (x < 0) x += mod;
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 최소공배수만큼 사이클이 생김

	cin >> t;
	while (t--) {
		ll m, n, x, y;
		cin >> m >> n >> x >> y;

		x--; y--;
			
		ll g = gcd(m, n);

		if ((y - x) % g != 0) {
			cout << -1 << "\n";
			continue;
		}

		// 중국인 나머지 정리
		ll lcm = m * n / g;

		ll d = (y - x) / g;
		ll mg = m / g;
		ll ng = n / g;

		ll inv = modinv(mg, ng);
		if (inv == -1) {
			cout << -1 << "\n";
			continue;
		}

		ll tmp = (d % ng) * inv % ng;
		ll ans = x + tmp * m;

		ans = ((ans % lcm) + lcm) % lcm; // 보정
		
		cout << ans + 1 << "\n";

	}


	return 0;
}