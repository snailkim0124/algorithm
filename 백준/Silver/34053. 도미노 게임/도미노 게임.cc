#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, m;
ll arr[1005][1005];
ll sum;
ll mn = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			sum += arr[i][j];
			mn = min(mn, arr[i][j]);
		}
	}

	cout << sum - mn;


	return 0;
}