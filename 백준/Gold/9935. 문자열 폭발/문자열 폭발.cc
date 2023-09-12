#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

string s, boom;
string res;
stack<char> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	cin >> boom;

	for (int i = 0; i < s.size(); i++) {
		st.push(s[i]);
		if (st.size() >= boom.size()) { // 스택사이즈와 폭탄 사이즈 비교
			if (st.top() == boom[boom.size() - 1]) { // 스택 top 부분과 폭탄 마지막 문자 비교
				string tmp = "";

				for (int j = 0; j < boom.size(); j++) {
					tmp += st.top(); // tmp에다가 s 넣기
					st.pop();
				}
				reverse(tmp.begin(), tmp.end());

				if (boom != tmp) { 
					for (int j = 0; j < tmp.size(); j++) {
						st.push(tmp[j]); // 폭탄과 tmp(임시 s)가 다르면 다시 복구
					}
				}
			}
		}
	}

	if (st.size() == 0) {
		cout << "FRULA";
	}
	else {
		while (st.size()) { // 결과값 입력
			res += st.top();
			st.pop();
		}
		reverse(res.begin(), res.end());
		cout << res;
	}

	return 0;
}