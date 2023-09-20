#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <tuple>

using namespace std;

int n;
int cnt;
int board[20];

void nqueen(int idx) {
	if (idx == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[idx] = i;
		bool check = true;
		for (int j = 0; j < idx; j++) {

			if (board[idx] == board[j] || idx - j == abs(board[idx] - board[j])) { // 열이랑 대각선이 같을때
				check = false;
			}
		}
		if (check) nqueen(idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	nqueen(0);
	cout << cnt;
	
	return 0;
}