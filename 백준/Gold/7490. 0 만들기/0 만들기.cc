#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t;
int n;
char ans[100];

void go(int depth, int ond, int sum, char lastOp) {
    if (depth == 2 * n - 1) {
        if (sum + (lastOp == '+' ? ond : -ond) == 0) {
            for (int i = 0; i < 2 * n - 1; i++) cout << ans[i];
            cout << "\n";
        }
        return;
    }

    ans[depth] = ' ';
    go(depth + 2, ond * 10 + (ans[depth + 1] - '0'), sum, lastOp);

    ans[depth] = '+';
    go(depth + 2, (ans[depth + 1] - '0'), sum + (lastOp == '+' ? ond : -ond), '+');

    ans[depth] = '-';
    go(depth + 2, (ans[depth + 1] - '0'), sum + (lastOp == '+' ? ond : -ond), '-');
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> t;
    while (t--) {
        memset(ans, 0, sizeof(ans));
        cin >> n;
        int num = 1;

        for (int i = 0; i < 2 * n; i += 2) {
            ans[i] = num++ + '0';
        }

        go(1, 1, 0, '+');
        cout << "\n";
    }
    

    return 0;
}