#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
vector<int> v;
int idx;
vector<int> ans;
int mx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp2 = i;
		int tmp3 = n - i;
		v.clear();
		v.push_back(n);
		v.push_back(tmp2);
		v.push_back(tmp3);

		while (1) {
			int tmp = tmp3;
			tmp3 = tmp2 - tmp3;
			if (tmp3 < 0) break;
			tmp2 = tmp;
			v.push_back(tmp3);
		}
		
		if (mx < (int)v.size()) {
			mx = v.size();
			ans = v;
		}
	}

	cout << mx << "\n";
	for (auto it : ans) {
		cout << it << " ";
	}

	
	return 0;
}