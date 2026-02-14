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
vector<int> adj[1005];
int e[1005], pref[1005];
int parent[1005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n;
		if (!n) break;

		for (int i = 2; i <= n; i++) {
			int p;
			cin >> p >> e[i];
			adj[p].push_back(i);
			parent[i] = p;
		}

		for (int i = 2; i <= n; i++) {
			pref[i] = e[i];
		}

		for (int i = n; i >= 2; i--) {
			pref[parent[i]] = min(pref[parent[i]], pref[i] - 1);
		}

		vector<pii> v;
		for (int i = 2; i <= n; i++) {
			v.push_back({ pref[i], i });
		}

		sort(all(v));

		//for (auto [a, b] : v) {
		//	cout << a << " : " << b << "\n";
		//}

		vector<int> ans;
		bool flag = true;
		for (int i = 0; i < v.size(); i++) {
			if (i > v[i].first) {
				flag = false;
				break;
			}
			else {
				ans.push_back(v[i].second);
			}
		}
		
		if (flag) {
			cout << "yes\n";
			for (auto it : ans) {
				cout << it << " ";
			}
			cout << "\n";
		}
		else cout << "no\n";
		
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		memset(parent, 0, sizeof(parent));
		memset(e, 0, sizeof(e));
		memset(pref, 0, sizeof(pref));
	}



	return 0;
}