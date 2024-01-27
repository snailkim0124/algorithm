#include <bits/stdc++.h>

using namespace std;


int n, c, m;
int start, _end, num;
int res;
vector<tuple<int, int, int>> v;
int capacity[2005]; // 남은 용량

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> start >> _end >> num;
		v.push_back({ _end, start, num }); // 받는, 보내는 ,박스 : (회의실 배정)
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		int mx = 0;
		for (int j = get<1>(v[i]); j < get<0>(v[i]); j++) {
			mx = max(mx, capacity[j]);
		}

		int tmp = min(get<2>(v[i]), c - mx);
		res += tmp; // 최대 용량 넣기

		for (int j = get<1>(v[i]); j < get<0>(v[i]); j++) {
			capacity[j] += tmp;
		}
	}

	cout << res;

	return 0;
}