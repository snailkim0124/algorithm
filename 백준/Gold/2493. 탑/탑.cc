#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[500005];
stack<pair<int, int>> st; // 높이, 인덱스
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	st.push({ 987654321, 0 }); // 초기화
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		while (!st.empty() && st.top().first < num) {
			st.pop();
		}
		ans.push_back(st.top().second);
		st.push({num, i});
	}

	for (auto it : ans) {
		cout << it << " ";
	}

	return 0;
}