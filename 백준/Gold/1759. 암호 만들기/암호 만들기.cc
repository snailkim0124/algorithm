#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int l, c;
vector<char> v;
vector<char> res;
int visited[20];

void go(int idx) {
	if ((int)res.size() == l) {
		int moum = 0;
		for (int i = 0; i < l; i++) {
			if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u') moum++;
		}

		int jaum = l - moum;
		if (moum >= 1 && jaum >= 2) {
			for (int i = 0; i < l; i++) {
				cout << res[i];
			}
			cout << "\n";
		}

		return;
	}

	for (int i = idx; i < c; i++) {
		res.push_back(v[i]);
		go(i + 1);
		res.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char al;
		cin >> al;
		v.push_back(al);
	}

	sort(all(v));

	go(0);

	return 0;
}