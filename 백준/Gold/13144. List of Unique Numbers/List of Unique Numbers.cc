#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll arr[100005];
ll cnt[100005];
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll left = 0;
	ll right = 0;
	while (right < n) {
		if (cnt[arr[right]] == 0) {
			cnt[arr[right]]++;
			right++;
		}
		else {
			res += right - left;
			cnt[arr[left]]--;
			left++;
		}
	}

	res += (ll)(right - left) * (right - left + 1) / 2;
	cout << res;
	return 0;
}