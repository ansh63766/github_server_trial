#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_digits(int n) {
    int digits = 0;
    while (n) {
        n = n / 10;
        digits++;
    }
    return digits;
}

int count_zeros(int n) {
    int zeros = 0;
    while (n % 10 == 0) {
        n = n / 10;
        zeros++;
    }
    return zeros;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int total_digits = 0;
        vector<int> z(n);
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = count_digits(v[i]);
            z[i] = count_zeros(v[i]);
            total_digits += d[i];
        }

        sort(z.rbegin(), z.rend());

        for (int i = 0; i < n; i += 2) {
            total_digits -= z[i];
        }

        if (total_digits >= m + 1) {
            cout << "Sasha" << endl;
        } else {
            cout << "Anna" << endl;
        }
    }
    return 0;
}