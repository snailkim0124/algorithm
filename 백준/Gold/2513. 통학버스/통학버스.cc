#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k, s;
vector<pii> leftv, rightv;
int res;

void printV(int idx, vector<pii>& v) {
	cout << "CASE : " << idx << "\n";
	for (auto it : v) {
		cout << it.first << " : " << it.second << "\n";
	}
	cout << "\n";
}

void Busing(vector<pii>& v) {
	int idx = 0;
	while (idx < v.size()) {
		// printV(idx, v);

		res += (v[idx].second / k) * abs(v[idx].first - s) * 2;
		v[idx].second %= k;

		if (v[idx].second == 0) {
			idx++;
			continue;
		}

		// pos로 처음 위치 저장하기
		if (v[idx].second < k) {
			int remain = k - v[idx].second;
			int pos = v[idx].first; // 11
			v[idx].second = 0;
			idx++;

			// 뭉쳐서 가기
			while (idx < v.size()) {
				// printV(idx, v);
				if (v[idx].second > remain) {
					v[idx].second -= remain;
					break;
				}
				else {
					remain -= v[idx].second;
					v[idx].second = 0;
				}

				idx++;
			}

			res += abs(pos - s) * 2;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		int pos, cnt;
		cin >> pos >> cnt;
		if (pos < s) {
			leftv.push_back({ pos, cnt });
		}
		else {
			rightv.push_back({ pos, cnt });
		}
	}

	// 먼 곳부터 정렬
	sort(leftv.begin(), leftv.end());
	sort(rightv.begin(), rightv.end(), greater<>());

	Busing(leftv);
	Busing(rightv);

	//cout << "left\n";
	//for (auto it : leftv) {
	//	cout << it.first << " : " << it.second << "\n";
	//}

	//cout << "right\n";
	//for (auto it : rightv) {
	//	cout << it.first << " : " << it.second << "\n";
	//}

	cout << res;

	return 0;
}