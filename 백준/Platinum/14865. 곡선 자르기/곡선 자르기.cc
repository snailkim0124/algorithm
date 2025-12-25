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
vector<pii> v;
vector<pii> peak; // x좌표만 담기

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	stack<pair<pii, pii>> st; // 선 스택
	for (int now = 0; now < n; now++) {
		int next = (now + 1) % n;

		// x좌표가 같음 (봉우리)
		if (v[now].first == v[next].first) {
			// 위로
			if (v[now].second <= 0 && v[next].second > 0) {
				st.push({ v[now], v[next] });
			}
			// 아래로
			else if (v[now].second > 0 && v[next].second <= 0) {
				st.push({ v[now], v[next] });

				// 봉우리 끝 : 시작 x좌표와 끝 x좌표 찾기
				if (st.size() >= 2) {
					vector<int> x;

					for (int i = 0; i < 2; i++) {
						auto [a, b] = st.top();
						st.pop();
						x.push_back(a.first);
					}

					// 작은 좌표가 왼쪽으로 가도록
					if (x[0] > x[1]) swap(x[0], x[1]);
					peak.push_back({ x[0], x[1] });
				}
			}
		}
	}

	// 나머지 처리
	if (st.size() >= 2) {
		vector<int> x;

		for (int i = 0; i < 2; i++) {
			auto [a, b] = st.top();
			st.pop();
			x.push_back(a.first);
		}

		// 작은 좌표가 왼쪽으로 가도록
		if (x[0] > x[1]) swap(x[0], x[1]);
		peak.push_back({ x[0], x[1] });
	}


	sort(all(peak));

	//cout << "peak\n";
	//for (auto [ax, bx] : peak) {
	//	cout << ax << " : " << bx << "\n";
	//}

	// 다른 봉우리에 포함되지 않는 봉우리
	stack<pii> st2;
	int idx = 0;

	while (idx < peak.size()) {
		st2.push(peak[idx++]);
		// top에 있는 봉우리가 감싼 경우
		while (!st2.empty() && (idx < peak.size()) && (st2.top().first <= peak[idx].first && peak[idx].second <= st2.top().second)) {
			idx++;
		}
	}

	// 다른 봉우리를 포함하지 않는 봉우리
	stack<pii> st3;
	idx = 0;
	while (idx < peak.size()) {
		if (!st3.empty()) {
			if (st3.top().first < peak[idx].first && peak[idx].second < st3.top().second) {
				st3.pop();
			}
		}
		st3.push(peak[idx++]);
	}

	cout << st2.size() << " " << st3.size() << "\n";


	return 0;
}