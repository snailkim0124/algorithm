#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
int cnt;
int arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int stod;
    cin >> n;
    if (n % 2 == 0) stod = n / 2;
    else stod = (n + 1) / 2;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) cnt++;
    }

    cout << max(0, stod - cnt);
    
    return 0;
}