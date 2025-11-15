#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int pizza;
int m, n;
map<int, int> mpa, mpb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> pizza;
	cin >> m >> n;
	vector<int> a(m + 1), prefa(2 * m + 1, 0);
	vector<int> b(n + 1), prefb(2 * n + 1, 0);

	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		prefa[i] = prefa[i - 1] + a[i];
	}

	// 배열을 2배 크기로 (원형)
	for (int i = 1; i <= m; i++) {
		prefa[m + i] = prefa[m + i - 1] + a[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		prefb[i] = prefb[i - 1] + b[i];
	}

	// 배열을 2배 크기로 (원형)
	for (int i = 1; i <= n; i++) {
		prefb[n + i] = prefb[n + i - 1] + b[i];
	}


	// 누적합 계산
	for (int sz = 1; sz <= m; sz++) {
		for (int start = 1; start <= m; start++) {
			int sum = prefa[start + sz - 1] - prefa[start - 1];
			mpa[sum]++;
			if (sz == m) break;
		}
	}

	for (int sz = 1; sz <= n; sz++) {
		for (int start = 1; start <= n; start++) {
			int sum = prefb[start + sz - 1] - prefb[start - 1];
			mpb[sum]++;
			if (sz == n) break;
		}
	}

	int res = mpa[pizza] + mpb[pizza];
	for (int i = 0; i < pizza; i++) {
		res += (mpa[i] * mpb[pizza - i]);
	}

	cout << res << "\n";

	
	return 0;
}