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
int arr[1005];
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int prev = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	prev = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] >= arr[i]) {
			ans = max(ans, arr[i - 1] - prev);
			prev = arr[i];
		}
	}

	ans = max(ans, arr[n - 1] - prev);

	cout << ans << "\n";
	

	return 0;
}