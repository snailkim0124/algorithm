#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;


int mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		set<int> st;
		int a, b, c;
		int res = 0;
		cin >> a >> b >> c;
		
		st.insert(a);
		st.insert(b);
		st.insert(c);

		//cout << st.size() << "\n";
		if (st.size() == 1) {
			res = 10000 + *st.begin()*1000;
		}
		else if (st.size() == 2) {
			res = 1000 + ((a + b + c) - (*st.begin() + *st.rbegin())) * 100;
		}
		else if (st.size() == 3) {
			res = *st.rbegin() * 100;
		}
		mx = max(mx, res);
	}

	cout << mx;
	
	return 0;
}