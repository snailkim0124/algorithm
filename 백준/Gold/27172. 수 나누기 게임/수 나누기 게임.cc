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
int x[100005];
int xx[10000005];
map<int, int> ans;
int mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		xx[x[i]]++;
		mx = max(mx, x[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = x[i] + x[i]; j <= mx; j += x[i]) {
			if (xx[j]) {
				ans[j]--;
				ans[x[i]]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[x[i]] << " ";
	}
	cout << "\n";
	

	return 0;
}