#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vector<pii> v;
int com[100005];
priority_queue<pii, vector<pii>, greater<pii>> pq; // 끝나는 시간, 자리
set<int> st; // 사용한 자리
int seat;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int p, q;
		cin >> p >> q;
		v.push_back({ p, q });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		while (!pq.empty()) {
			if (pq.top().first <= v[i].first) {
				st.insert(pq.top().second);
				pq.pop();
			}
			else break;
		}

		if (st.empty()) {
			pq.push({ v[i].second, seat });
			com[seat]++;
			seat++;
		}
		else {
			pq.push({ v[i].second, *st.begin()});
			com[*st.begin()]++;
			st.erase(st.begin());
		}
	}

	cout << seat << "\n";
	for (int i = 0; i < seat; i++) {
		cout << com[i] << " ";
	}
	

	return 0;
}