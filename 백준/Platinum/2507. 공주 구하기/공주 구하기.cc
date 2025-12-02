#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int mod = 1000;
int n;
int dp[505][505];
int dist[505], spring[505], flag[505];

bool check(int s, int e) {
	if (spring[s] < abs(dist[s] - dist[e])) return false; // 점프 가능?
	if (e < s && flag[e] == 0) return false; // 돌아올 때 쓸수 있는가
	
	return true;
}

int go(int s, int e) {
	if (dp[s][e] != -1) return dp[s][e] % mod;

	dp[s][e] = 0;
	if (s == n && e == n) dp[s][e] = 1;

	if (s == n) {
		for (int i = e + 1; i <= n; i++) {
			if (check(i, e)) {
				dp[s][e] += go(s, i);
			}
		}
	}
	else if (e == n) {
		for (int i = s + 1; i <= n; i++) {
			if (check(s, i)) {
				dp[s][e] += go(i, e);
			}
		}
	}
	else {
		for (int i = min(s, e) + 1; i <= n; i++) {
			if (s == min(s, e)) {
				if (i != e && check(s, i)) dp[s][e] += go(i, e);
			}
			else if (e == min(s, e)) {
				if (i != s && check(i, e)) dp[s][e] += go(s, i);
			}
		}
	}

	dp[s][e] %= mod;
	return dp[s][e];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> dist[i] >> spring[i] >> flag[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << go(1, 1) % mod << "\n";
	
	return 0;
}