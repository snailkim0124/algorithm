#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n ; i++)
#define rrep(i, r, n) for(int i = r; i < n ; i++)
#define rrrep(i, r, n) for(ll i = r; i < n ; i++)
#define _rrep(i, r, n) for(int i = r; i >= n; i--)
#define _rrrep(i, r, n) for(ll i = r; i >= n; i--)

using namespace std;
typedef long long ll;

void print_arr(int n, int arr[][305]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

void odd_num(int n, int(&arr)[305][305]) {
	int x, y; //이전 숫자 위치
	rrep(i, 1, n * n + 1) {
		if (i == 1) { //1. 정사각형 맨 아랫줄 가운데에 숫자1 기록
			arr[n - 1][n / 2] = 1;
			x = n - 1;
			y = n / 2;
			continue;
		}

		//이전숫자 오른쪽 아래칸이 맵밖인가?
		if (x + 1 >= n || y + 1 >= n) { //2. 맵 밖일때
			//2-1. 수평(좌)으로 이동하여 기록되지 않은 빈칸에 다음 숫자를 기록
			if (x + 1 < n) {
				rep(j, n) {
					if (arr[x + 1][j] == 0) {
						arr[x + 1][j] = i;
						x = x + 1;
						y = j;
						break;
					}
				}
			}
			else if (y + 1 < n) { //2-2. 수직(상)으로 이동하여 기록되지 않은 빈칸에 숫자를 기록
				rep(j, n) {
					if (arr[j][y + 1] == 0) {
						arr[j][y + 1] = i;
						x = j;
						y = y + 1;
						break;
					}
				}
			}
			else { //2-3. 수평, 수직으로 이동불가능하면 이전숫자의 윗칸에 다음숫자를 기록
				arr[x - 1][y] = i;
				x = x - 1;
				y = y;
			}

		}
		else { //맵 안일때
			if (arr[x + 1][y + 1] == 0) { //3. 오른쪽 아래칸이 비어있으면 다음숫자를 기록
				arr[x + 1][y + 1] = i;
				x = x + 1;
				y = y + 1;
			}
			else { //4. 오른쪽 아래칸이 채워져있는 경우 이전숫자의 윗칸에 다음숫자를 기록
				arr[x - 1][y] = i;
				x = x - 1;
				y = y;
			}
		}
	}
}

void even_num(int n, int(&arr)[305][305]) {

	int sub[305][305] = { 0 };
	int k = n / 2;
	odd_num(k, sub);

	int kk = k / 2;
	//기본 세팅
	rrep(i, k, n) { //C
		rep(j, k) {
			arr[i][j] = 3;
		}
	}
	rep(i, k) { //B
		rrep(j, k, n) {
			if (n - kk < j)
				arr[i][j] = 1;
			else
				arr[i][j] = 2;
		}
	}
	rrep(i, k, n) { //D
		rrep(j, k, n) {
			if (n - kk < j)
				arr[i][j] = 2;
			else
				arr[i][j] = 1;
		}
	}

	rep(i, kk) {
		rep(j, kk) {
			arr[i][j] = 3;
			arr[i + k][j] = 0;
		}
	}

	rrep(j, 1, kk + 1) { //가운데를 바꿈
		arr[kk][j] = 3;
		arr[3 * kk + 1][j] = 0;
	}

	rrep(i, k - kk, k) {
		rep(j, kk) {
			arr[i][j] = 3;
			arr[i + k][j] = 0;
		}
	}

	//세팅된 마방진에 size*size/4를 전부 곱함
	rep(i, n)
		rep(j, n)
		arr[i][j] *= (n * n) / 4;

	//printAll();

	//미리구한 n/2 * n/2 마방진을 각  4분할에 더함
	rep(i, k) {
		rep(j, k) {
			arr[i][j] += sub[i][j]; //A
			arr[i][j + k] += sub[i][j]; //C
			arr[i + k][j + k] += sub[i][j]; //B
			arr[i + k][j] += sub[i][j]; //D
		}
	}
}

void four_num(int n, int(&arr)[305][305]) {
	bool cross[305 + 1][305 + 1] = { false };
	int k = n / 4;
	rep(i, n) {
		rep(j, n) {
			if ((0 <= i && i <= k - 1 && 0 <= j && j <= k - 1)
				|| (0 <= i && i <= k - 1 && 3 * k <= j)
				|| (3 * k <= i && 0 <= j && j <= k - 1)
				|| (3 * k <= i && 3 * k <= j))
				cross[i][j] = true;
			if (k <= i && i <= 3 * k - 1 && k <= j && j <= 3 * k - 1)
				cross[i][j] = true;
		}
	}
	bool num[305 * 305 + 2] = { false };
	rep(i, n) {
		rep(j, n) {
			if (cross[i][j]) {
				arr[i][j] = n * i + j + 1;
				num[n * i + j + 1] = true;
			}
		}
	}
	int tmp;
	rrep(i, 1, 305 * 305 + 2) { //시작할수를 찾음
		tmp = i;
		if (!num[i])
			break;
	}

	_rrep(i, n - 1, 0) {
		_rrep(j, n - 1, 0) {
			if (!cross[i][j]) { //대각선이 아닌곳
				arr[i][j] = tmp;
				num[tmp] = true;
				rrep(i, tmp + 1, 305 * 305 + 2) { //다음 k수를 찾음
					tmp++;
					if (!num[i])
						break;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	int arr[305][305] = { 0 };

	cin >> n;
	if (n % 2 == 1) odd_num(n, arr);
	else {
		if (n % 4 == 0) four_num(n, arr);
		else even_num(n, arr);
	}

	print_arr(n, arr);
	return 0;
}