#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

bool isprime[500005];
ll n;
ll dp[500005];
ll freq[500005]; // 빈도수
vector<pll> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(isprime, isprime + 500005, 1);
	isprime[0] = isprime[1] = 0;

	for (int i = 2; i * i <= 500000; i++) {
		if (isprime[i]) {
			for (int j = i + i; j <= 500000; j += i) {
				isprime[j] = 0;
			}
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		freq[num]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (freq[i]) {
			v.push_back({i, freq[i]});
		}
	}

	n = v.size();

	// knapsack
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int val = 500000; val >= 0; val--) {
			for (int j = 1; j <= v[i].second; j++) {
				if (val - (v[i].first * j) < 0) break;

				dp[val] += dp[val - (v[i].first * j)];
			}
		}
	}

	ll sum = 0;
	for (int i = 2; i <= 500000; i++) {
		if (isprime[i]) sum += dp[i];
	}

	// 0인 경우
	sum = sum * (freq[0] + 1);

	cout << sum << "\n";

	return 0;
}