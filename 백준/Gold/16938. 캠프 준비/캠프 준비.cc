#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, l, r, x;
int arr[20];
int cnt;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int bit = 0; bit < (1 << n); bit++) {
		int sum = 0, mx = 0, mn = 987654321, cnt_select = 0;

		for (int i = 0; i < n; i++) {
			if (bit & (1 << i)) {
				sum += arr[i];
				mx = max(mx, arr[i]);
				mn = min(mn, arr[i]);
				cnt_select++;
			}
		}

		if (cnt_select >= 2 && l <= sum && sum <= r && abs(mx - mn) >= x) cnt++;

	}
	
	cout << cnt << "\n";
	
	return 0;
}