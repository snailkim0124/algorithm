#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, q;
int arr[1000005];
int pref[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pref[i] = pref[i - 1] ^ arr[i];
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << pref[i] << " ";
	//}
	//cout << "\n";

	int ans = 0;
	while (q--) {
		int s, e;
		cin >> s >> e;
		ans ^= (pref[e] ^ pref[s - 1]);
	}
	
	cout << ans << "\n";

	return 0;
}