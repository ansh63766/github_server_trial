#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_square(ll s) {
    if (s < 0) return false;
    ll root = sqrtl(s);
    return root * root == s;
}

void solve() {
    ll n;
    cin >> n;
    ll total = n * (n + 1) / 2;
    if (is_square(total)) {
        cout << -1 << '\n';
        return;
    }
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        p[i] = n - i;
    }
    for (int i = 1; i <= n - 1; ++i) {
        ll sum_rev = (ll)i * (2 * n - i + 1) / 2;
        if (is_square(sum_rev)) {
            swap(p[i - 1], p[i]);
        }
    }
    for (int x : p) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}