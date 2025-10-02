#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

string s, e, q;
int sn, en, qn;
set<string> mps, mpe;
string t, m;
int res;

int timetoint(string time) {
	return (int)(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> e >> q;
	sn = timetoint(s);
	en = timetoint(e);
	qn = timetoint(q);

	while (cin >> t >> m) {
		int tn = timetoint(t);
		if (tn <= sn) mps.insert(m);
		else if (en <= tn && tn <= qn) mpe.insert(m);
	}

	vector<string> ans;
	set_intersection(all(mps), all(mpe), back_inserter(ans));

	cout << ans.size() << "\n";

	return 0;
}