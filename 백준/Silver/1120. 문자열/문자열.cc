#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string a, b;
int mx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    for (int i = 0; i <= b.size() - a.size(); i++) {
        int cnt = 0;
        string tmp = b.substr(i, a.size());
        for (int j = 0; j < a.size(); j++) {
            if (tmp[j] == a[j]) cnt++;
        }
        mx = max(mx, cnt);
    }

    cout << a.size() - mx;
   
    return 0;
}