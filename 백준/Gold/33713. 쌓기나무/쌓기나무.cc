#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

ll n, m, q;
map<pll, ll> mp;
map<ll, map<ll, ll>> mpx, mpy;
ll front, side = 0;
ll top;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> q;
	while (q--) {
		string cmd;
		int i, j;
		cin >> cmd;
		if (cmd == "STACK") {
			cin >> i >> j;
			ll tmp = mp[{i, j}];
			if (!tmp) top++;
			mp[{i, j}]++;

			ll xmx = mpx[i].empty() ? 0 : mpx[i].rbegin()->first;
			if (tmp > 0) {
				mpx[i][tmp]--;
				if (!mpx[i][tmp]) mpx[i].erase(tmp);
			}
			mpx[i][tmp + 1]++;
			front += (mpx[i].rbegin()->first - xmx);

			ll ymx = mpy[j].empty() ? 0 : mpy[j].rbegin()->first;
			if (tmp > 0) {
				mpy[j][tmp]--;
				if (!mpy[j][tmp]) mpy[j].erase(tmp);
			}
			mpy[j][tmp + 1]++;
			side += (mpy[j].rbegin()->first - ymx);

		}
		else if (cmd == "REMOVE") {
			cin >> i >> j;
			ll tmp = mp[{i, j}];
			if (tmp > 0) {
				mp[{i, j}]--;
				if (!mp[{i, j}]) top--;

				ll xmx = mpx[i].rbegin()->first;
				mpx[i][tmp]--;
				if (!mpx[i][tmp]) mpx[i].erase(tmp);
				if (tmp - 1 > 0) mpx[i][tmp - 1]++;
				ll nxmx = mpx[i].empty() ? 0 : mpx[i].rbegin()->first;
				front += (nxmx - xmx);

				ll ymx = mpy[j].rbegin()->first;
				mpy[j][tmp]--;
				if (!mpy[j][tmp]) mpy[j].erase(tmp);
				if (tmp - 1 > 0) mpy[j][tmp - 1]++;
				ll nymx = mpy[j].empty() ? 0 : mpy[j].rbegin()->first;
				side += (nymx - ymx);
			}
		}
		else if (cmd == "FRONT") {
			// x
			cout << front << "\n";
		}
		else if (cmd == "SIDE") {
			// y
			cout << side << "\n";
		}
		else if (cmd == "TOP") {
			cout << top << "\n";
		}
	}


	return 0;
}