#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, l;
ll arr[100005];
vector<pll> v;
ll mxp, mxm;
ll cnt, leftcnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] < 0) {
			leftcnt++;
			mxm = max(mxm, abs(arr[i]));
		}
		else {
			mxp = max(mxp, l - arr[i]);
		}
		v.push_back({ abs(arr[i]), i });
	}

	sort(v.begin(), v.end());

	if (mxm > mxp) {
		cout << v[leftcnt - 1].second << " " << mxm;
	}
	else {
		cout << v[leftcnt].second << " " << mxp;
	}

	return 0;
}