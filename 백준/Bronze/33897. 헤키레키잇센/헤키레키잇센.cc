#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[300005];
int cnt = 1;
int mx = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int prev = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			mx = max(mx, i + 1 - prev);
			cnt++;
			prev = i + 1;

		}
	}
	mx = max(mx, n - prev);
	
	cout << cnt << " " << mx;

	return 0;
}