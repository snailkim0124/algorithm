#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int arr[1005];
int brr[1005];
int sum;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    sort(arr, arr + n);
    sort(brr, brr + n);

    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - brr[i]);
    }

    cout << sum;

    
    return 0;
}