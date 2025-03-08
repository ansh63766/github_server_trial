#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    vector<int> zeros;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            zeros.push_back(i);
        }
    }

    long long ans = 0;

    // Count all substrings of all 0s
    for (int i = 0; i < zeros.size(); ) {
        int j = i;
        while (j < zeros.size() && (j == i || zeros[j] == zeros[j-1] + 1)) {
            ++j;
        }
        int len = j - i;
        ans += (long long)len * (len - 1) / 2;
        i = j;
    }

    // Count other valid substrings where zeros > ones and have at least two adjacent 0s (linear or circular)
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i+1] = pre[i] + (s[i] == '0');
    }

    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            int cnt0 = pre[r+1] - pre[l];
            int cnt1 = (r - l + 1) - cnt0;
            if (cnt0 > cnt1) {
                bool hasAdjacent = false;
                for (int i = l; i <= r; ++i) {
                    if (s[i] == '0' && (i < r && s[i+1] == '0' || (i == r && s[l] == '0'))) {
                        hasAdjacent = true;
                        break;
                    }
                }
                if (hasAdjacent) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}