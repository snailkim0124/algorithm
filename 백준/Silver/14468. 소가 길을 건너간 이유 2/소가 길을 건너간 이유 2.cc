#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s;
vector<pii> v(26);
int visited[26];
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(visited, -1, sizeof(visited));

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (visited[s[i] - 'A'] == -1) visited[s[i] - 'A'] = i;
		else v[s[i] - 'A'] = { visited[s[i] - 'A'], i };
	}

	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			int a1 = v[i].first, a2 = v[i].second;
			int b1 = v[j].first, b2 = v[j].second;

			if ((a1 < b1 && b1 < a2 && a2 < b2) || (b1 < a1 && a1 < b2 && b2 < a2)) {
				res++;
			}
		}
	}

	cout << res << "\n";
	
	return 0;
}