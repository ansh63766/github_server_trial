#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Flip signs of elements at even indices
    for (int i = 1; i < n; i += 2) {
        a[i] = -a[i];
    }

    // Compute prefix sums
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    // Check if any two prefix sums are equal
    set<long long> seen;
    for (int i = 0; i <= n; i++) {
        if (seen.count(prefix[i])) {
            cout << "YES\n";
            return;
        }
        seen.insert(prefix[i]);
    }

    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}