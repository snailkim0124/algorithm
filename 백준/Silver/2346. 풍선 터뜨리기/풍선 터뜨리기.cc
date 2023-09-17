#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>
#include <deque>

using namespace std;

int n;
deque<pair<int, int>> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		dq.push_back({ num, i + 1 }); // 풍선 번호, 인덱스
	}

	while (!dq.empty()) { // 덱이 빌 때까지
		int now = dq.front().first;
		cout << dq.front().second << " "; // 출력
		dq.pop_front();

		if (dq.empty()) break; // 종료조건

		if (now > 0) {
			now--; // pop_front 때문에 -1
			for (int i = 0; i < now; i++) { 
				dq.push_back(dq.front()); // 맨앞을 맨뒤로
				dq.pop_front();
			}
		}
		else {
			now = -now; // 음수를 양수로
			for (int i = 0; i < now; i++) {
				dq.push_front(dq.back()); // 맨뒤를 맨앞으로
				dq.pop_back();
			}
		}
	}

	return 0;
}