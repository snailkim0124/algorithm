#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

char arr[15][15];
int n;

bool check(int y, int x, int sz) {
    if(y + sz > n || x + sz > n) return false;

    for(int i = y; i < y + sz; i++) {
        for(int j = x ; j < x + sz; j++) {
            if(arr[i][j] == '#') return false;
        }
    }

    return true;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int mx = 0;
    for(int i =0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 1; k <= n; k++) {
                if(check(i, j, k)) {
                    mx = max(mx, k);
                }
            }
        }
    }
    
    cout << mx << "\n";

    memset(arr, 0, sizeof(arr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
    
    return 0;
}