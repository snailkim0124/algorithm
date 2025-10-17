#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

typedef struct SHARK {
	int r, c, s, d, z;
	bool operator == (SHARK tmp) {
		return (r == tmp.r && c == tmp.c && s == tmp.s && d == tmp.d && z == tmp.z);
	}

}SHARK;

int R, C, M;
const int dr[5] = { 0,-1,1,0,0 }; // 1 : 위, 2 : 아래, 3 : 오른쪽, 4 : 왼쪽
const int dc[5] = { 0,0,0,1,-1 };
vector<SHARK> shark;
int res;

void fish_shark(int fisher) {
	SHARK catched;
	int mnr = 987654321;
	int idx = -1;

	for (int i = 0; i < shark.size(); i++) {
		if (shark[i].c == fisher && shark[i].r < mnr) {
			mnr = shark[i].r;
			idx = i;
		}
	}

	if (idx != -1) {
		res += shark[idx].z;
		shark.erase(shark.begin() + idx);
	}
}

void shark_move() {
	vector<vector<SHARK>> tmp(R + 1, vector<SHARK>(C + 1, { 0,0,0,0,0 }));

	for (auto& it : shark) {
		auto [r, c, s, d, z] = it;

		if (d <= 2) s %= (2 * R - 2);
		else s %= (2 * C - 2);

		for (int i = 0; i < s; i++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (nr < 1 || nr >R || nc < 1 || nc > C) {
				if (d == 1) d = 2;
				else if (d == 2) d = 1;
				else if (d == 3) d = 4;
				else if (d == 4) d = 3;

				nr = r + dr[d];
				nc = c + dc[d];
			}

			r = nr; c = nc;
		}

		if (tmp[r][c].z == 0 || tmp[r][c].z < z) {
			tmp[r][c] = { r,c,s,d,z };
		}
	}

	shark.clear(); // 기존 상어 초기화
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (tmp[r][c].z > 0) shark.push_back(tmp[r][c]); // 큰 상어만 추가
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> M;
	while (M--) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark.push_back({ r,c,s,d,z });
	}

	// cout << "Vsize : " << shark.size() << "\n";
	for (int fisher = 1; fisher <= C; fisher++) {
		fish_shark(fisher);
		// cout << "after : " << shark.size() << "\n";
		// break;
		shark_move();
	}

	cout << res;

	return 0;
}