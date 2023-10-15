#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll dp[105][105];
ll arr[105];

ll check(int idx, int sum) {
	if (sum < 0 || sum>20) return 0;

	ll& res = dp[idx][sum];
	if (res != 0) return res;

	if (idx == n - 2) {
		if (sum == arr[n - 1]) return 1; // 같으면
		else return 0;
	}

	res += check(idx + 1, sum + arr[idx + 1]); // 더하기
	res += check(idx + 1, sum - arr[idx + 1]); // 빼기
	return res;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << check(0, arr[0]);

	return 0;
}