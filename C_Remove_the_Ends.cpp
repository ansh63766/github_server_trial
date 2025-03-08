#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<long long> ps(n, 0);
        vector<long long> ns(n, 0);

        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                ps[i] = (i >= 1 ? ps[i - 1] : 0LL) + a[i];
            } else {
                ps[i] = (i >= 1 ? ps[i - 1] : 0LL);
            }
        }

        long long max_sum = LLONG_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < 0) {
                ns[i] = (i + 1 < n ? ns[i + 1] : 0LL) - a[i];
            } else {
                ns[i] = (i + 1 < n ? ns[i + 1] : 0LL);
            }
            max_sum = max(max_sum, ns[i] + ps[i]);
        }

        cout << max_sum << endl;
    }
    return 0;
}