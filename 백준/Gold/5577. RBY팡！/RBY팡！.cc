#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<int> arr;
vector<pii> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	int prev = 0;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
		if (i == 0) {
			prev = num;
			continue;
		}

		if (prev != num) {
			v.push_back({ prev, i - idx });
			prev = num;
			idx = i;
		}
	}

	v.push_back({ prev, n - idx });

	
	vector<int> pref(v.size() + 1, 0);
	
	for (int i = 1; i < v.size(); i++) {
		pref[i] = pref[i - 1] + v[i - 1].second;
	}

	vector<pii> candi; // 인덱스, 색깔

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second == 1) {
			if (i - 1 >= 0 && i + 1 < v.size() && v[i - 1].first == v[i + 1].first) {
				if (v[i - 1].second + v[i + 1].second >= 3) {
					candi.push_back({ pref[i], v[i - 1].first });
				}
			}
		}
		else if (v[i].second == 3) {
			if (pref[i] + 3 < n) candi.push_back({ pref[i] + 3, v[i].first });
			if (pref[i] - 1 >= 0) candi.push_back({ pref[i] - 1, v[i].first });
		}
	}

	int res = n;
	for (auto [idx, color] : candi) {
		//cout << idx << " : " << color << "\n";
		vector<int> tmp = arr;
		tmp[idx] = color;

		vector<pii> vv;

		// 터뜨리기
		for (auto it : tmp) {
			if (vv.empty()) {
				vv.push_back({ it, 1 });
			}
			else {
				if (vv.back().first == it) {
					vv.back().second++;
				}
				else {
					if (vv.back().second >= 4) {
						vv.pop_back();

						if (!vv.empty() && vv.back().first == it) {
							vv.back().second++;
						}
						else vv.push_back({ it, 1 });
					}
					else {
						vv.push_back({ it, 1 });
					}
				}
			}
		}

		if (!vv.empty() && vv.back().second >= 4) {
			vv.pop_back();
		}

		int sum = 0;
		for (auto it : vv) {
			sum += it.second;
		}

		res = min(res, sum);
	}


	cout << res << "\n";

	//for (int i = 0; i < v.size(); i++) {
	//	cout << pref[i] << " ";
	//}
	//cout << "\n";

	//for (auto [a, b] : v) {
	//	cout << a << " : " << b << "\n";
	//}
    

	return 0;
}