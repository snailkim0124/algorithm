#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n;
ll arr[1000005];
stack<ll> st;
vector<ll> v;
ll mx;
ull res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		// 연속한 수를 한묶음으로
		if (!st.empty() && st.top() == num) continue;

		st.push(num);
		v.push_back(num);
	}

	st = stack<ll>();

	for (int i = 0; i < v.size(); i++) {
		if (!st.empty() && st.top() < v[i]) {
			res += v[i] - st.top();

			while (!st.empty() && st.top() < v[i]) {
				st.pop();
			}
		}

		st.push(v[i]);
	}

	// 남은거 처리
	ll prev = -1;
	while (st.size() > 1) {
		prev = st.top();
		st.pop();

		res += st.top() - prev;
	}

	cout << res << "\n";


	return 0;
}