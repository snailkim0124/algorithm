#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 0 ; i< n; i++) {
		int num;
		cin >> num;
		if(num != 1) v.push_back(num);
	}

	if(v.size() == 1) {
		bool flag = false;
		for(int i = 2; i * i<= v[0]; i++) {
			if(v[0] % i == 0) {
				flag = true;
			}
		}

		if(!flag) cout << "NO\n";
		else {
			cout << "YES\n";
			cout << 2 << "\n";
			cout << 1 << " " << v[0] << "\n";
		}
	}
	else {
		cout << "YES\n";
		cout << v.size() << "\n";
		for(auto it : v) {
			cout << it << " ";
		}
		cout << "\n";
	}


	return 0;
}