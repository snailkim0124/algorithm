#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k, s;
vector<pii> leftv, rightv;
int res;

void Busing(vector<pii>& v) {
	int idx = 0;
	while (idx < v.size()) {
		res += (v[idx].second / k) * abs(v[idx].first - s) * 2;
		v[idx].second %= k;

		if (v[idx].second == 0) {
			idx++;
			continue;
		}

		// pos로 처음 위치 저장하기
		int remain = k;
		int pos = v[idx].first;

		// 뭉쳐서 가기
		while (idx < v.size()) {
			if (v[idx].second > remain) {
				v[idx].second -= remain;
				break;
			}
			else {
				remain -= v[idx].second;
			}
			idx++;
		}

		res += abs(pos - s) * 2;
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

	cout << res;

	return 0;
}