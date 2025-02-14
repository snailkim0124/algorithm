#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m;
int arr[15];
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        sum += arr[num];
    }

    cout << sum;
    
    return 0;
}