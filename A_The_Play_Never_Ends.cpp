#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        cout << ((k - 1) % 3 == 0 ? "YES" : "NO") << endl;
    }
    return 0;
}
