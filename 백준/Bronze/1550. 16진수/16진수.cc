#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string s;
int res;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> s;
    for(int i = 0; i<s.size(); i++) {
        int num;
        if(s[i] >= 'A' && s[i] <= 'F') {
            num = s[i] - 'A' + 10;
        }
        else {
            num = s[i] - '0';
        }
        res += pow(16, s.size() - 1 - i) * num;
    }
    
    cout << res;
    
    
	return 0;
}