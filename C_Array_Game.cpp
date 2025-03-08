#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<long long> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        if (k >= 3) {
            cout << 0 << endl;
            continue;
        }

        long long min_diff = LLONG_MAX;
        for (int i = 0; i < n - 1; i++) {
            min_diff = min(min_diff, v[i + 1] - v[i]);
        }

        if (k == 1) {
            cout << min_diff << endl;
            continue;
        }

        long long mini = min_diff;
        for (int i = 0; i < n-1; i++) {
            long long diff = abs(v[i] - v[i+1]);
            for (int j = 0; j < n; j++) {
                mini = min(mini, abs(diff - v[j]));
            }
        }

        cout << mini << endl;
    }

    return 0;
}