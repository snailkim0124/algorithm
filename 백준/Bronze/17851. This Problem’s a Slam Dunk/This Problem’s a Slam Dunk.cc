#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int arr[15];
int brr[15];
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++) {
        cin >> brr[i];
    }

    sort(arr, arr + 5);
    sort(brr, brr + 5);

    for (int i = 0; i < 5; i++) {
        if (arr[i] > brr[i]) cnt++;
    }

    cout << cnt;
    
    return 0;
}