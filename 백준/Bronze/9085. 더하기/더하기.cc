#include <iostream>

using namespace std;

int t;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int sum = 0;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            sum += temp;
        }

        cout << sum << "\n";
    }
}