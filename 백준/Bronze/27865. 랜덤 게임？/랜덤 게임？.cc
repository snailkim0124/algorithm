#include <bits/stdc++.h>
#include <random>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n; 

char query(int x) {
	cout << "? " << x << endl;
	char res;
	cin >> res;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	while (1) {
		if (query(1) == 'Y') break;
	}

	cout << "! 1" << endl;
	
	return 0;
}