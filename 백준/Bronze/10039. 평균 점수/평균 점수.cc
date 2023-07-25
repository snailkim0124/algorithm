#include <iostream>

using namespace std;

int n;
int sum;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        cin >> n;
        if (n < 40) n = 40;
        sum += n;
    }
    cout << sum / 5;
}