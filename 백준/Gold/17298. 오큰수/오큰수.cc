#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>

using namespace std;

int n;
stack<int> st;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		int num;
		cin >> num;
		v.push_back(num);
		while (1) {
			if (st.empty()) {
				st.push(i);
				break;
			}
			if (num > v[st.top()]) {
				v[st.top()] = num;
				st.pop();
			}
			else {
				st.push(i);
				break;
			}
		}
	}

	while (!st.empty()) {
		v[st.top()] = -1;
		st.pop();
	}

	for (auto it : v) cout << it << " ";



	return 0;
}