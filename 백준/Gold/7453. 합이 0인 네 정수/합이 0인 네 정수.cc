#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n;
ll a[4005], b[4005], c[4005], d[4005];
vector<ll> ab, cd;
ll res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab.push_back(a[i] + b[j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cd.push_back(c[i] + d[j]);
		}
	}

	sort(ab.begin(), ab.end());
	sort(cd.begin(), cd.end());

	ll left = 0;
	ll right = n * n - 1;

	while (left < n * n && right >= 0) {
		if (ab[left] + cd[right] < 0) left++;
		else if (ab[left] + cd[right] > 0) right--;
		else {
			ll cntab = 1;
			ll cntcd = 1;
			while (ab[left] == ab[left + cntab] && left + cntab < n * n) cntab++;
			while (cd[right] == cd[right - cntcd] && right - cntcd >= 0) cntcd++;
			res += cntab * cntcd;
			left += cntab;
			right -= cntcd;
		}
	}

	cout << res;


	return 0;
}