#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

int n;
int cnt = 1;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0 ; i < n ; i++) {
		int num;
		cin >> num;

		if (num == cnt) cnt++;
		else st.push(num);

		while (!st.empty() && st.top() == cnt) {
			st.pop();
			cnt++;
		}
	}

	if (!st.empty()) cout << "Sad";
	else cout << "Nice";

	return 0;
}