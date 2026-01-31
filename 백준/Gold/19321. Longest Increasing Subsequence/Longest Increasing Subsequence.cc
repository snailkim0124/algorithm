#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, mx;
vector<int> v[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	vector<int> a(n);
	vector<int> p(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v[a[i]].push_back(i);
		mx = max(mx, a[i]);
	}


	int idx = 1;
	
	for (int i = 1; i <= mx; i++) {
		sort(all(v[i]), greater<>());
		
		for (auto now : v[i]) {
			p[now] = idx++;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << p[i] << " ";
	}
	cout << "\n";





	

	return 0;
}