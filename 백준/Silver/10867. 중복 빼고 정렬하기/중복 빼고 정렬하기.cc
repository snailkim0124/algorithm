#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int t;
int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}