#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> a(n);
        map<pair<int, int>, int> m;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[{a[i] % x, a[i] % y}]++;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int f = a[i] % x;
            int s = a[i] % y;

            m[{f, s}]--;

            int comp_f = (x - f) % x; 
            if (m.find({comp_f, s}) != m.end()) {
                ans += m[{comp_f, s}];
            }
        }

        cout << ans << endl;
    }

    return 0;
}