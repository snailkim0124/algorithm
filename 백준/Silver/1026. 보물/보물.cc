#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int n, num;
vector<int> a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        a.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        b.push_back(num);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), less<int>());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    cout << sum;
    return 0;
}