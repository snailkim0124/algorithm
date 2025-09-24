#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;

int prime[5000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 2; i < 5000005; i++) {
        prime[i] = i;
    }
    for (int i = 2; i * i < 5000005; i++) {
        for (int j = i * i; j < 5000005; j += i) {
            if (prime[j] == j) {
                prime[j] = i;
            }
        }
    }
    
    int n;
    cin >> n;
    while (n--) {
        int k;
        cin >> k;

        while (k > 1) {
            cout << prime[k] << " ";
            k /= prime[k];
        }

        cout << "\n";
    }

    return 0;
}