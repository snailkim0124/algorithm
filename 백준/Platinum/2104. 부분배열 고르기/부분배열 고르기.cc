#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll arr[100005];
int n;
ll res;
stack<pair<ll, ll>> st; // { arr, 계속 더하는 값 }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n + 1; i++) {
		ll tmp = 0;
		while (!st.empty() && arr[i] < st.top().first) {
			tmp += st.top().second;
			res = max(res, tmp * st.top().first); // 최솟값 곱하기
			st.pop();
		}
		tmp += arr[i];
		st.push({ arr[i], tmp });
	}

	cout << res;

	return 0;
}