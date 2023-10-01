#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
deque<int> dq;
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (a[i] == 0) {
			dq.push_back(num);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		dq.push_front(x);
		cout << dq.back() << " ";
		dq.pop_back();
	}

	return 0;
}