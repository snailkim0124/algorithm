#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
int cnt[55];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cnt[num]++;
	}

	for (int i = 50; i >= 0; i--) {
		if (cnt[i] == i) {
			cout << i << "\n";
			exit(0);
		}
	}

	cout << -1 << "\n";

	return 0;
}