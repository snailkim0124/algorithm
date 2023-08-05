#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<int> a;
int n;
int sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 7; i++) {
        int num;
        cin >> num;
        if (num % 2 == 1) {
            a.push_back(num);
            sum += num;
        }
    }

    sort(a.begin(), a.end());

    if (a.empty()) {
        cout << -1;
    }
    else {
        cout << sum << "\n" << a.front();
    }
    return 0;
}