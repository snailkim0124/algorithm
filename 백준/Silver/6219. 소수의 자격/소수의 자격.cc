#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


bool check[4000001];
vector<int> v;
ll a, b, cnt;
char d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	check[1] = 1;
	for (int i = 2; i * i < 4000000; i++) {
		if (check[i] == false) {
			for (int j = i * i; j < 4000000; j += i) {
				check[j] = true;
			}
		}
	}

	cin >> a >> b >> d;

	for (int i = a; i <= b; i++) {
		if (!check[i]) {
			string tmp = to_string(i);
			if (tmp.find(d) != string::npos) {
				cnt++;
			}
			
		}
	}

	cout << cnt;

    
    return 0;
}