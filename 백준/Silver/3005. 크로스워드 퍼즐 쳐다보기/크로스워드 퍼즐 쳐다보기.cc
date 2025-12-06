#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c;
char arr[25][25];
vector<string> v, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		string tmp = "";
		for (int j = 0; j < c; j++) {
			tmp += arr[i][j];
		}
		v.push_back(tmp);
	}

	for (int j = 0; j < c; j++) {
		string tmp = "";
		for (int i = 0; i < r; i++) {
			tmp += arr[i][j];
		}
		v.push_back(tmp);
	}

	for (auto it : v) {
		if (it.find('#') != string::npos) {
			string tmp = "";
			for (int i = 0; i < it.size(); i++) {
				if (it[i] != '#') {
					tmp += it[i];
				}
				else {
					if (tmp.size() >= 2) {
						ans.push_back(tmp);
					}
					tmp = "";
				}
			}

			if (tmp.size() >= 2) {
				ans.push_back(tmp);
			}
		}
		else ans.push_back(it);
	}

	sort(all(ans));

	cout << ans[0] << "\n";
	
	return 0;
}