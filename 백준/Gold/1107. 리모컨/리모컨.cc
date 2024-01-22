#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string n;
int m;
bool button[15];
int channel = 100;
const int INF = 987654321;
int cnt1, cnt2 = INF;

bool check(int num) {
	string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		if (!button[s[i] - '0']) {
			return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	fill(button, button + 15, true);

	cin >> n;
	cin >> m;
	while (m--) {
		int num;
		cin >> num;
		button[num] = false;
	}
	// 일일이 +, - 버튼 누르기
	cnt1 = abs(stoi(n) - 100);
	// 모든 버튼이 있을 때
	for (int i = 0; i <= 1000000; i++) {
		if (check(i)) {
			//  +,- 버튼 + 숫자 버튼 누르는 수
			int num = abs(stoi(n) - i) + to_string(i).size();
			cnt2 = min(cnt2, num);
		}
	}

	cout << min(cnt1, cnt2);

	return 0;
}