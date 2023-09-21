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
int a[1005];
int memo[1005];
int cnt[1005];
int res = 1;
int idx;
vector<int> res_list;

void go(int idx) {
	if (idx == -1) return;
	res_list.push_back(a[idx]); // res_list에 계속 저장
	go(memo[idx]); // 저장해놓은 인덱스 탐색
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	fill(memo, memo + 1005, -1); // 초기화 하기
	fill(cnt, cnt + 1005, 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && cnt[i] < cnt[j] + 1) {
				cnt[i] = cnt[j] + 1; // 카운트 max 해주기
				memo[i] = j; // 인덱스 저장

				if (res < cnt[i]) {
					res = cnt[i]; // 개수 세기
					idx = i; // 최종 인덱스 저장
				}
			}
		}
	}

	cout << res << "\n";
	go(idx);
	reverse(res_list.begin(), res_list.end());

	for (auto it : res_list) {
		cout << it << " ";
	}

	return 0;
}