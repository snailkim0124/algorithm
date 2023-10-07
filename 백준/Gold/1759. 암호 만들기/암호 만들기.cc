#include <bits/stdc++.h>

using namespace std;

int L, C;
vector<char> a;
vector<char> res;

void dfs(int start) {
	if ((int)res.size() == L) {
		int aeiou = 0;
		for (int i = 0; i < L; i++) {
			if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') aeiou++;
		}
		if (aeiou >= 1 && L - aeiou >= 2) { // 모음, 자음 체크
			for (int i = 0; i < L; i++) {
				cout << res[i];
			}
			cout << "\n";
		}
		return;
	}
	else {
		for (int i = start; i < C; i++) {
			res.push_back(a[i]);
			dfs(i + 1);
			res.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char alpha;
		cin >> alpha;
		a.push_back(alpha);
	}

	sort(a.begin(), a.end());
	dfs(0);
	
	return 0;
}