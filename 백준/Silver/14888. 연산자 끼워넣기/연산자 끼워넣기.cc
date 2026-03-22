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
int arr[15];
int mx = INT_MIN;
int mn = INT_MAX;

void go(int idx, int plus, int minus, int multi, int div, int val) {
	if (idx == n) {
		mx = max(mx, val);
		mn = min(mn, val);
		return;
	}

	if (plus > 0) {
		go(idx + 1, plus - 1, minus, multi, div, val + arr[idx]);
	}
	if (minus > 0) {
		go(idx + 1, plus, minus - 1, multi, div, val - arr[idx]);
	}
	if (multi > 0) {
		go(idx + 1, plus, minus, multi - 1, div, val * arr[idx]);
	}
	if (div > 0) {
		go(idx + 1, plus, minus, multi, div - 1, val / arr[idx]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int plus, minus, multi, div;
	cin >> plus >> minus >> multi >> div;

	go(1, plus, minus, multi, div, arr[0]);
	
	cout << mx << "\n";
	cout << mn << "\n";

	return 0;
}