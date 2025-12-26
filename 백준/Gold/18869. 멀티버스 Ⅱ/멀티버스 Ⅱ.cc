#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int m, n;
int visited[10005];
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	vector<vector<int>> arr(m, vector<int>(n));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}

		map<int, int> mp; // 좌표 압축용
		vector<int> tmp = arr[i];
		sort(all(tmp));

		tmp.erase(unique(all(tmp)), tmp.end()); // 중복 원소 제거

		int idx = 0;
		for (int j = 0; j < tmp.size(); j++) {
			mp[tmp[j]] = idx++;
		}

		for (int j = 0; j < n; j++) {
			arr[i][j] = mp[arr[i][j]];
		}
	}

	for (int now = 0; now < m; now++) {
		for (int i = 0; i < m; i++) {
			if (now == i) continue;

			bool flag = true;
			for (int j = 0; j < n; j++) {
				if (arr[now][j] != arr[i][j]) {
					flag = false;
				}
			}

			if (flag) {
				cnt++;
			}
		}
	}

	cout << cnt / 2 << "\n";

	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	return 0;
}