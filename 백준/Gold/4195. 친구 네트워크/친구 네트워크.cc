#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int f;
int parent[200002];
int friends[200002];
map<string, int> mp;

int findParent(int a) {
	if (a == parent[a]) {
		return a;
	}
	else {
		return parent[a] = findParent(parent[a]);
	}
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		// 친구수 적은 곳에 추가
		if (friends[a] < friends[b]) swap(a, b);
		parent[b] = a;
		friends[a] += friends[b];
	}
}

bool check(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a == b) {
		return 1;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		mp.clear();
		cin >> f;
		int cnt = 1;
		for (int i = 1; i <= 200000; i++) {
			parent[i] = i;
			friends[i] = 1;
		}

		for (int i = 0; i < f; i++) {
			string a, b;
			cin >> a >> b;

			// 없으면 추가
			if (mp.find(a) == mp.end()) mp[a] = cnt++; 
			if (mp.find(b) == mp.end()) mp[b] = cnt++;

			unionParent(mp[a], mp[b]);

			cout << friends[findParent(mp[a])] << "\n";
		}
	}
	

	return 0;
}