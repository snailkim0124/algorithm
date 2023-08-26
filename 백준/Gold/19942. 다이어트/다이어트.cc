#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int n;
int A, B, C, D, E;
int mp, mf, ms, mv;
int res = 2000000001;
map<int, vector<vector<int>>> res_v;

typedef struct list {
	int a;
	int b;
	int c;
	int d;
	int e;
}LIST;

LIST arr[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d >> arr[i].e;
	}

	for (int i = 1; i < (1 << n); i++) {
		A = B = C = D = E = 0;
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				v.push_back(j + 1);
				A += arr[j].a;
				B += arr[j].b;
				C += arr[j].c;
				D += arr[j].d;
				E += arr[j].e;
			}
		}
		if (A >= mp && B >= mf && C >= ms && D >= mv) {
			if (res >= E) {
				res = E;
				res_v[res].push_back(v);
			}
		}
	}

	if (res == 2000000001) cout << -1;
	else {
		cout << res << "\n";
		sort(res_v[res].begin(), res_v[res].end());
		for (int it : res_v[res][0]) {
			cout << it << " ";
		}
	}
	return 0;
}