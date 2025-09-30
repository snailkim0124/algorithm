#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int u, n;
int visited[10005];
vector<pair<string, int>> v;
vector<int> tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> u >> n;
	for (int i = 0; i < n; i++) {
		string s; int p;
		cin >> s >> p;
		v.push_back({ s, p });
		visited[p]++;
	}

	int mn = 987654321;
	for (int i = 1; i <= u; i++) {
		if (visited[i]) mn = min(mn, visited[i]);
	}

	for (int i = 1; i <= u; i++) {
		if (visited[i] == mn) {
			tmp.push_back(i);
		}
	}

	sort(all(tmp));

	for (int i = 0; i < n; i++) {
		if (v[i].second == tmp[0]) {
			cout << v[i].first << " " << v[i].second << "\n";
			break;
		}
	}

	return 0;
}