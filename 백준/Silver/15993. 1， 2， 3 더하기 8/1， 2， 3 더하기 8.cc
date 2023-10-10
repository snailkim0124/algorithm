#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[100005];
ll odd[100005]; // 홀수
ll even[100005]; // 짝수
ll mod = 1000000009;
int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	odd[1] = 1; even[1] = 0;
	odd[2] = 1; even[2] = 1;
	odd[3] = 2; even[3] = 2;
	for (int i = 4; i <= 100000; i++) {
		even[i] = odd[i - 1] % mod + odd[i - 2] % mod + odd[i - 3] % mod;
		even[i] %= mod;
		odd[i] = even[i - 1] % mod + even[i - 2] % mod + even[i - 3] % mod;
		odd[i] %= mod;
	}

	while (t--) {
		cin >> n;
		cout << odd[n] << " " << even[n] << "\n";
	}
	return 0;
}