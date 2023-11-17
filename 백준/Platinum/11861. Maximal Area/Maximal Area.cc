#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int arr[1000005];
stack<int> st;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	st.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int tmp = st.top();
			st.pop();
			res = max(res, arr[tmp] * (i - st.top() - 1));
		}
		st.push(i);
	}

	cout << res;

	return 0;
}