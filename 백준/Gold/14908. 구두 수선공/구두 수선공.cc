#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef struct SHOES {
	int idx; 
	double t, s;
}SHOES;
int n;
vector<SHOES> v;

bool cmp(SHOES& a, SHOES& b) {
	if ((a.t / a.s) == (b.t / b.s)) return a.idx < b.idx;
	else return ((a.t / a.s) < (b.t / b.s));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		double t, s;
		cin >> t >> s;
		v.push_back({ i, t, s });
	}

	sort(v.begin(), v.end(), cmp);

	for (auto it : v) {
		cout << it.idx << " ";
	}

	
	return 0;
}