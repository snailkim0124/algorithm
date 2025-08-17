#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[15];
int res;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            res ^= (arr[i] | arr[j]);
            for (int k = j + 1; k < 10; k++) {
                res ^= (arr[i] | arr[j] | arr[k]);
            }
        }
    }

    cout << res;
    
    return 0;
}