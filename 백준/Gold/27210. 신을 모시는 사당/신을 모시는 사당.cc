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
int arr[100005];
int lpref[100005];
int rpref[100005];
int dp[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		lpref[i] = lpref[i - 1] + (arr[i] == 1);
		rpref[i] = rpref[i - 1] + (arr[i] == 2);
	}


	int mx = 0;
	int mn = 0;

	for (int i = 1; i <= n; i++) {
		mx = max(mx, lpref[i] - rpref[i]);
		mn = min(mn, lpref[i] - rpref[i]);

	}

	cout << mx - mn << "\n";
	

	return 0;
}