#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<ll> plusarr;
vector<ll> minusarr;
ll res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		if (num > 0) plusarr.push_back(num);
		else minusarr.push_back(num);
	}

	sort(plusarr.begin(), plusarr.end(), greater<>());
	sort(minusarr.begin(), minusarr.end());

	for (int i = 0; i < plusarr.size(); i += 2) {
		ll mul = 1;
		ll sum = 0;
		mul *= plusarr[i];
		sum += plusarr[i];
		if (i +1 < plusarr.size()) {
			mul *= plusarr[i + 1];
			sum += plusarr[i + 1];
		}
		res += max(mul, sum);
	}

	for (int i = 0; i < minusarr.size(); i += 2) {
		ll mul = 1;
		mul *= minusarr[i];
		if (i + 1 < minusarr.size()) mul *= minusarr[i + 1];
		res += mul;
	}
	
	cout << res;

	return 0;
}
