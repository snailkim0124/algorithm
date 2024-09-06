#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int x, y;
vector<int> res;
ll ans;

vector<int> tobin(int n) {
	vector<int> bin;

	while (n > 0) {
		bin.push_back(n % 2);
		n /= 2;
	}

	while (bin.size() < 16) {
		bin.push_back(0);
	}

	//reverse(bin.begin(), bin.end());

	return bin;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;
	vector<int> bin_x = tobin(x);
	vector<int> bin_y = tobin(y);

	for (int i = 0; i < 16; i++) {
		res.push_back(bin_y[i]);
		res.push_back(bin_x[i]);
	}

	for (int i = 0; i < res.size(); i++) {
		ans += pow(2, i) * res[i];
	}

	cout << ans;

	return 0;
}