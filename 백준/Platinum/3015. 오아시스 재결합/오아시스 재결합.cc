#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll height;
stack<pll> st;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> height;
		ll cnt = 1;
		while (!st.empty()) {
			if (st.top().first > height) break; // 키가 작으면 스택에 넣기

			res += st.top().second;
			if (st.top().first == height) {
				cnt = st.top().second + 1;
			}
			else cnt = 1;
			st.pop();
		}

		if (!st.empty()) res++; // 내림차순
		st.push({ height, cnt });
	}

	cout << res;
	

	return 0;
}