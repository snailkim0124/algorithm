#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int r, c, k;
int arr[105][105];
int num[105];
int mxr = 3, mxc = 3;

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;
	r--; c--;

	for (int i = 0; i < mxr; i++) {
		for (int j = 0; j < mxc; j++) {
			cin >> arr[i][j];
		}
	}

	for (int T = 0; T <= 100; T++) {
		if (arr[r][c] == k) {
			cout << T << "\n";
			exit(0);
		}

		if (mxr >= mxc) {
			int mx = 0;
			for (int i = 0; i < mxr; i++) {
				memset(num, 0, sizeof(num));
				vector<pii> v;

				for (int j = 0; j < mxc; j++) {
					num[arr[i][j]]++;
				}

				for (int k = 1; k <= 100; k++) {
					if (num[k]) v.push_back({ k, num[k] });
				}

				sort(all(v), cmp);

				int idx = 0;
				for (auto it : v) {
					arr[i][idx++] = it.first;
					arr[i][idx++] = it.second;
				}

				for (int j = idx; j < 100; j++) {
					arr[i][j] = 0;
				}

				mx = max(mx, idx);
			}

			mxc = mx;
		}
		else {
			int mx = 0;
			for (int i = 0; i < mxc; i++) {
				memset(num, 0, sizeof(num));
				vector<pii> v;

				for (int j = 0; j < mxr; j++) {
					num[arr[j][i]]++;
				}

				for (int k = 1; k <= 100; k++) {
					if (num[k]) v.push_back({ k, num[k] });
				}

				sort(all(v), cmp);

				int idx = 0;
				for (auto it : v) {
					arr[idx++][i] = it.first;
					arr[idx++][i] = it.second;
				}

				for (int j = idx; j < 100; j++) {
					arr[j][i] = 0;
				}

				mx = max(mx, idx);
			}

			mxr = mx;
		}

	}

	cout << -1 << "\n";



	return 0;
}