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
vector<int> order;
int arr[405][405];
int ans[25][25];
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,1,0,-1 };

int check1(int num, int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (ans[ny][nx] != 0 && arr[num][ans[ny][nx]]) cnt++;
	}

	return cnt;
}

int check2(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (!ans[ny][nx]) cnt++;
	}

	return cnt;
}

void go(int num) {
	// 1. 비어 있는 칸 중 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리
	vector<pii> candi;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] != 0) continue;

			int val = check1(num, i, j);
			if (mx == val) {
				candi.push_back({ i, j });
			}
			else if (mx < val) {
				mx = val;
				candi.clear();
				candi.push_back({ i, j });
			}
		}
	}

	if (candi.size() == 1) {
		auto [y, x] = candi[0];
		ans[y][x] = num;
		return;
	}

	// 2. 인접한 칸 중에서 비어있는 칸이 가장 많은 칸
	vector<pii> candi2;
	mx = -1;
	for (auto [y, x] : candi) {
		int val = check2(y, x);
		if (mx == val) {
			candi2.push_back({ y, x });
		}
		else if (mx < val) {
			mx = val;
			candi2.clear();
			candi2.push_back({ y, x });
		}
	}

	if (candi2.size() == 1) {
		auto [y, x] = candi2[0];
		ans[y][x] = num;
		return;
	}

	// 3. 행의 번호가 가장 작은 칸
	sort(all(candi2));

	auto [y, x] = candi2[0];
	ans[y][x] = num;
	return;
}

int score(int y, int x) {
	int num = ans[y][x];
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		int like = ans[ny][nx];
		if (like != 0 && arr[num][like]) cnt++;
	}

	return pow(10, cnt - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int num;
		cin >> num;
		order.push_back(num);
		for (int j = 0; j < 4; j++) {
			int like;
			cin >> like;
			arr[num][like]++;
		}
	}

	for (auto num : order) {
		go(num);
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << ans[i][j] << " ";
	//	}
	//	cout << "\n";
	//}


	int res = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res += score(i, j);
		}
	}

	cout << res << "\n";
	
	return 0;
}