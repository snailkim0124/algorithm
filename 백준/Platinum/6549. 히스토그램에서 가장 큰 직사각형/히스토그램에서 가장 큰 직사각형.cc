#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll arr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		int n;
		ll res = 0;
		stack<ll> st;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		if (n == 0) break;

		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		arr[n + 1] = 0;

		st.push(0);
		for (int i = 1; i <= n + 1; i++) {
			while (!st.empty() && arr[st.top()] > arr[i]) {
				ll tmp = arr[st.top()];
				st.pop();
				ll tmp2 = i - st.top() - 1;
				res = max(res, tmp * tmp2);
			}
			st.push(i);
		}

		cout << res << "\n";
	}

	return 0;
}