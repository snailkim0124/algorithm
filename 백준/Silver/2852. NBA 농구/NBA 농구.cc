#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int s1, s2;
vector<pii> v;
int team1, team2;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &n);
	for (int T = 1; T <= n; T++) {
		int team, m, s;
		scanf("%d %d:%d", &team, &m, &s);

		s += m * 60;

		v.push_back({ team, s });
	}
	v.push_back({ 0, 48 * 60 }); // 끝나는 시간 넣기

	for (int i = 0; i < v.size(); i++) {
		if (i != 0) {
			if (team1 > team2) {
				s1 += v[i].second - v[i - 1].second;
			}
			else if (team1 < team2) {
				s2 += v[i].second - v[i - 1].second;
			}
		}

		if (v[i].first == 1) team1++;
		else if (v[i].first == 2) team2++;
	}
	printf("%02d:%02d\n", s1 / 60, s1 % 60);
	printf("%02d:%02d\n", s2 / 60, s2 % 60);

	return 0;
}