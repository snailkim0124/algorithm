#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int n, m;
int one;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (num == 1) one++;
        v.push_back(num);
    }

    if (n == 2) {
        if (one == 0 || one == m) {
            cout << 1 << "\n";
            if (one == 0) {
                cout << 1 << " " << 0 << " " << 1 << "\n";
                cout << 1 << " " << 1 << " " << 2 << "\n";
            }
            else {
                cout << 1 << " " << 1 << " " << 2 << "\n";
                cout << 1 << " " << 1 << " " << 3 << "\n";
            }
            for (int i = 0; i < m; i++) {
                cout << 2 << " " << 1 << " " << 2 << "\n";
            }
        }
        else cout << -1 << "\n";
        exit(0);
    }

    cout << 1 << "\n";
    cout << 1 << " " << 0 << " " << 1 << "\n";
    cout << 1 << " " << 1 << " " << 2 << "\n";
    cout << 1 << " " << 1 << " " << 3 << "\n";

    for (int i = 0; i < n - 3; i++) {
        cout << 1 << " " << 20 << " " << 21 << "\n";
    }

    for (int i = 0; i < m; i++) {
        if (v[i] == 1) {
            cout << 2 << " " << 2 << " " << 3 << "\n";
        }
        else if (v[i] == 0) {
            cout << 2 << " " << 1 << " " << 2 << "\n";
        }
    }
    
    return 0;
}