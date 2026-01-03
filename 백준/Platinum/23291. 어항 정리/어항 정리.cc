#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

const int INF = 987654321;
int n, k;
vector<vector<int>> arr;
const int dy[2] = { 0,1 };
const int dx[2] = { 1,0 };

// 물고기 수 조절
void fish_adjust() {

	// 차분 배열
	vector<vector<int>> diff(105, vector<int>(105, 0));

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			for (int dir = 0; dir < 2; dir++) {
				int ny = dy[dir] + i;
				int nx = dx[dir] + j;

				if (ny >= arr.size() || nx >= arr[ny].size()) continue;

				int d = abs(arr[i][j] - arr[ny][nx]) / 5;

				if (d > 0) {
					if (arr[i][j] > arr[ny][nx]) {
						diff[i][j] -= d;
						diff[ny][nx] += d;
					}
					else {
						diff[ny][nx] -= d;
						diff[i][j] += d;
					}
				}

			}
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			arr[i][j] += diff[i][j];
		}
	}

	// 일렬로 놓기 (왼쪽, 아래 -> 위)
	vector<int> floor;

	for (int j = 0; j < arr[0].size(); j++) {
		for (int i = 0; i < arr.size(); i++) {
			if (j < arr[i].size()) {
				floor.push_back(arr[i][j]);
			}
		}
	}

	// 초기화
	arr.clear();
	arr.push_back(floor);
}

// 어항 정리
void fish_sort() {
	// 1. 가장 적은 어항에 물고기 넣기
	int mn = INF;
	for (int i = 0; i < arr[0].size(); i++) {
		mn = min(mn, arr[0][i]);
	}

	for (int i = 0; i < n; i++) {
		if (mn == arr[0][i]) arr[0][i]++;
	}

	// 2. 어항 쌓기

	// 처음 가로, 세로
	int tmpx = 1;
	int tmpy = 1;

	while (arr[0].size() - tmpx >= tmpy) {
		vector<vector<int>> narr; // 다음 arr

		// 쌓을 부분
		vector<vector<int>> tmp;
		for (int i = 0; i < tmpy; i++) {
			vector<int> r;
			for (int j = 0; j < tmpx; j++) {
				r.push_back(arr[i][j]);
			}
			tmp.push_back(r);
		}

		// 나머지
		vector<int> floor;
		for (int j = tmpx; j < arr[0].size(); j++) {
			floor.push_back(arr[0][j]);
		}
		narr.push_back(floor);

		// 회전 쌓기
		for (int j = tmpx - 1; j >= 0; j--) {
			vector<int> r;
			for (int i = 0; i < tmpy; i++) {
				r.push_back(tmp[i][j]);
			}
			narr.push_back(r);
		}


		tmpy = narr.size();
		tmpx = narr[1].size();
		arr = narr;
	}

	// 3. 물고기 수 조절, 일렬로 놓기
	fish_adjust();

	// 4. 어항 쌓기 (2번 반복)
	vector<vector<int>> narr;
	int ban = arr[0].size() / 2;

	vector<int> up, down;
	for (int i = 0; i < ban; i++) {
		up.push_back(arr[0][ban - 1 - i]); // 180도 회전
	}
	for (int i = ban; i < arr[0].size(); i++) {
		down.push_back(arr[0][i]);
	}

	narr.push_back(down);
	narr.push_back(up);
	arr = narr;

	// 한번 더
	narr.clear();
	ban = arr[0].size() / 2;

	// 밑
	for (int j = 0; j < 2; j++) {
		vector<int> r;
		for (int i = ban; i < arr[0].size(); i++) {
			r.push_back(arr[j][i]);
		}
		narr.push_back(r);
	}

	// 위 (180도 회전)
	for (int j = 1; j >= 0; j--) {
		vector<int> r;
		for (int i = ban - 1; i >= 0; i--) {
			r.push_back(arr[j][i]);
		}
		narr.push_back(r);
	}

	arr = narr;

	// 5. 물고기 조절, 일렬로 놓기
	fish_adjust();
}



// 어항 최대 최소 확인 작업
bool check() {
	int mx = -1;
	int mn = INF;

	for (int i = 0; i < arr[0].size(); i++) {
		mx = max(mx, arr[0][i]);
		mn = min(mn, arr[0][i]);
	}

	return ((mx - mn) <= k);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	vector<int> floor(n);
	for (int i = 0; i < n; i++) {
		cin >> floor[i];
	}
	arr.push_back(floor);

	int cycle = 0;
	while (1) {
		if (check()) {
			/*for (int i = 0; i < arr[0].size(); i++) {
				cout << arr[0][i] << " ";
			}
			cout << "\n";*/
			cout << cycle << "\n";
			break;
		}

		fish_sort();
		cycle++;
	}

	return 0;
}