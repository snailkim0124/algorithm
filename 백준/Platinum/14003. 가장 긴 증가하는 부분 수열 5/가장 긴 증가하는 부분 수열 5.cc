#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <map>

using namespace std;
int n;
int arr[1000005];
pair<int, int> v[1000005];
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(arr, arr + 1000005, 1000000000); // 큰 수로 초기화
	cin >> n;

	int size = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		auto pos = lower_bound(arr, arr + size, num); // lower_bound로 
		int int_pos = (int)(lower_bound(arr, arr + size, num) - arr);

		if (*pos == 1000000000) size++; // 초기화 된 부분이라면
		*pos = num; 

		v[i].first = int_pos; // 인덱스
		v[i].second = num; // arr 요소들
	}
	
	cout << size << "\n";
	for (int i = n - 1; i >= 0; i--) {
		if (v[i].first == size - 1) {
			st.push(v[i].second); // 스택에다 집어넣기
			size--;
		}
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}