#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const ll mod = 1e9 + 7;
ll n, k;
ll arr[500005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	ll remain = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		remain += arr[i];
	}

	remain = k - remain; // 남은 칸수

	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans = (ans * (remain + i)) % mod;
	}

	cout << ans << "\n";


	return 0;
}