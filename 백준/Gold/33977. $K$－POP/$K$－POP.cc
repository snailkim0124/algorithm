#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int k;
int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            a = i;
        }
    }

    b = k / a;
    if ((b - a) <= 1) {
        // 완전 이진 트리

        int node = 1;

        cout << a + b << "\n";

        for (int i = 1; i <= a + b; i++) {
            cout << i << " " << ++node << "\n";
            if (node == a + b) break;

            cout << i << " " << ++node << "\n";
            if (node == a + b) break;
        }
    }
    else {
        cout << a + b << "\n";

        for (int i = 1; i <= b; i++) {
            cout << i << " " << i + 1 << "\n";
        }

        int node = b + 1;
        for (int i = 1; i < a; i++) {
            cout << i << " " << ++node << "\n";
        }
    }
    
    return 0;
}