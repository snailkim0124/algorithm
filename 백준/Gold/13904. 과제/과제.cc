#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<pii> v;
int visited[1005];
int res;
int mx;

bool cmp(pii& a, pii& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		int d, w;
		cin >> d >> w;
		v.push_back({ d, w });
		mx = max(mx, d);
	}

	sort(v.begin(), v.end(), cmp);

	//for (auto it : v) {
	//	cout << it.first << " : " << it.second << "\n";
	//}

	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i].first; j > 0; j--) {
			if (!visited[j]) {
				visited[j] = v[i].second;
				break;
			}
		}
	}

	for (int i = 1; i <= mx; i++) {
		res += visited[i];
	}

	cout << res;
	
	return 0;
}