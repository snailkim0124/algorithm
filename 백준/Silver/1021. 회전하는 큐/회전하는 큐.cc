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

int n, m;
deque<int> dq;
int cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dq.push_back(i); // 큐 크기만큼
	}

	while (m--) {
		int num, idx;
		cin >> num;

		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				idx = i;
				break;
			}
		}

		if (idx < dq.size() - idx) {
			while (1) {
				if (dq.front() == num) {
					dq.pop_front(); // 첫번째 원소 뽑기
					break;
				}
				cnt++;
				dq.push_back(dq.front()); // 맨앞을 맨뒤로
				dq.pop_front();
			}
		}
		else {
			while (1) {
				if (dq.front() == num) {
					dq.pop_front(); // 첫번째 원소 뽑기
					break;
				}
				cnt++;
				dq.push_front(dq.back()); // 맨뒤를 맨앞으로
				dq.pop_back();
			}
		}
	}

	cout << cnt;

	return 0;
}