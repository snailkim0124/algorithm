#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
char arr[50][50];
int ans[50];

bool check(int idx) {
    int sum = 0;
    for (int i = idx; i >= 0; i--) {
        sum += ans[i];
        if (arr[i][idx] == '+' && sum <= 0) return false;
        if (arr[i][idx] == '-' && sum >= 0) return false;
        if (arr[i][idx] == '0' && sum != 0) return false;
    }

    return true;
}

void go(int depth) {
    if (depth == n) {
        for (int i = 0; i < depth; i++) {
            cout << ans[i] << " ";
        }
        exit(0);
    }

    for (int i = -10; i <= 10; i++) {
        ans[depth] = i;
        if (check(depth)) go(depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    go(0);

    return 0;
}