#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool possible(ll mid, const vector<pair<ll, ll>> &v) {
    ll x = 0, y = 0;

    for (auto [a, b] : v) {
        x -= mid;
        y += mid;

        x = max(x, a);
        y = min(y, b);

        if (x > y) return false;
    }

    return true;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        vector<pair<ll, ll>> v(n);
        for (ll i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            v[i] = {x, y};
        }

        ll ans = 1e9, low = 0, high = 1e9, mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (possible(mid, v)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }
}
