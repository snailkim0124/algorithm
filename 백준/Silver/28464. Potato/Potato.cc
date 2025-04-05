#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[200005];
int a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        a += arr[i];
    }

    sort(arr, arr + n);

    for (int i = 0; i < n / 2; i++) {
        b += arr[i];
    }
    
    cout << b << " " << a - b;

    return 0;
}