#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

vector<ll> v, lmx, rmx, lmn, rmn;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	v.resize(n + 1);
	lmx.resize(n + 1);
	rmx.resize(n + 1);
	lmn.resize(n + 1);
	rmn.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	stack<ll> st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && v[st.top()] <= v[i]) {
			st.pop();
		}

		lmx[i] = 1;
		if (!st.empty()) lmx[i] = st.top() + 1;
		st.push(i);
	}

	st = stack<ll>();
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && v[st.top()] < v[i]) {
			st.pop();
		}

		rmx[i] = n;
		if (!st.empty()) rmx[i] = st.top() - 1;
		st.push(i);
	}

	st = stack<ll>();
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && v[st.top()] >= v[i]) {
			st.pop();
		}

		lmn[i] = 1;
		if (!st.empty()) lmn[i] = st.top() + 1;
		st.push(i);
	}

	st = stack<ll>();
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && v[st.top()] > v[i]) {
			st.pop();
		}

		rmn[i] = n;
		if (!st.empty()) rmn[i] = st.top() - 1;
		st.push(i);
	}



	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll mx = (i - lmx[i] + 1) * (rmx[i] - i + 1);
		ll mn = (i - lmn[i] + 1) * (rmn[i] - i + 1);
		ans += (mx - mn) * v[i];
	}

	cout << ans << "\n";


	return 0;
}