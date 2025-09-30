#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;


char arr[25][25];
int m, n;
int u, l, r, d;
string puzzle[15];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if ((i + j) % 2 == 0) arr[i][j] = '#';
            else arr[i][j] = '.';
        }
    }

    cin >> m >> n;
    cin >> u >> l >> r >> d;
    for (int i = 0; i < m; i++) {
        cin >> puzzle[i];
    }


    for (int i = u; i < u + m; i++) {
        for (int j = l; j < l + n; j++) {
            arr[i][j] = puzzle[i - u][j - l];
        }
    }

    for (int i = 0; i < u + d + m; i++) {
        for (int j = 0; j < l + r + n; j++) {
            cout << arr[i][j] << "";
        }
        cout << "\n";
    }
    
    return 0;
}