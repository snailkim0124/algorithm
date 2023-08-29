#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int n, m;
vector<int> arr, ans;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        
        cout << upper_bound(arr.begin(), arr.end(), num) - lower_bound(arr.begin(), arr.end(), num) << " ";
    }

    return 0;
}