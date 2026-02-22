#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

struct SNAKE {
	deque<pii> body;
	int dir;
};

int n, k, l;
int arr[105][105];
SNAKE snake;
const int dy[4] = { -1,0,1,0 }; // 상우하좌
const int dx[4] = { 0,1,0,-1 };

void printarr(int t) {
	cout << "========================\n";
	cout << t << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "========================\n";
}

void go(int prev, int now, char c) {
	for (int T = prev + 1; T <= now; T++) {
		//printarr(T);
		// 몸길이 늘리기
		auto [hy, hx] = snake.body.front();
		hy += dy[snake.dir];
		hx += dx[snake.dir];

		if (hy < 0 || hx < 0 || hy >= n || hx >= n || arr[hy][hx] == 1) {
			cout << T << "\n";
			exit(0);
		}
		
		bool apple = (arr[hy][hx] == 2);
		// 머리가 다음칸
		snake.body.push_front({ hy, hx });
		arr[hy][hx] = 1;

		if (!apple) {
			auto [ty, tx] = snake.body.back();
			arr[ty][tx] = 0;
			snake.body.pop_back(); // 꼬리 자르기
		}
	}
	
	// 머리 회전
	if (c == 'L') snake.dir = (snake.dir + 3) % 4;
	else if (c == 'D') snake.dir = (snake.dir + 1) % 4;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int y, x;
		cin >> y >> x;
		y--; x--;
		arr[y][x] = 2; // 사과
	}

	snake.body.push_back({ 0, 0 });
	snake.dir = 1;
	arr[0][0] = 1; // 뱀

	int prev = 0;
	cin >> l;
	while (l--) {
		int x; char c;
		cin >> x >> c;
		go(prev, x, c);
		prev = x;
	}

	go(prev, 10000, '@');

	return 0;
}