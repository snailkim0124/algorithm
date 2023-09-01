#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

using namespace std;
int n;
int a[1000005]; // 입력 리스트
int cnt[1000005]; // 카운팅 정렬
int res[1000005]; // 결과 리스트
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(&res[0], &res[0] + 1000005, -1); // -1로 초기화

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++; // 카운팅
	}

	for (int i = 0; i < n; i++) {
		while (!st.empty() && cnt[a[st.top()]] < cnt[a[i]]) {
			res[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	return 0;
}