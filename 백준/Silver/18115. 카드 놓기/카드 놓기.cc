#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1000005];
deque<int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int idx = 1;


	for (int i = n; i >= 1; i--) {
		if (arr[i] == 1) {
			// 뒤에다가 넣기
			dq.push_back(idx++);
		}
		else if (arr[i] == 2) {
			int top = dq.back();
			dq.pop_back();
			dq.push_back(idx++);
			dq.push_back(top);
		}
		else if (arr[i] == 3) {
			// 앞에다가 넣기
			dq.push_front(idx++);
		}
	}

	while (!dq.empty()) {
		cout << dq.back() << " ";
		dq.pop_back();
	}
	
	
	return 0;
}