#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 2; i <= n; ++i) {
            cin >> p[i];
        }

        vector<int> depth(n + 1, 0);
        for (int i = 2; i <= n; ++i) {
            depth[i] = depth[p[i]] + 1;
        }

        int max_depth = *max_element(depth.begin(), depth.end());
        vector<vector<int>> levels(max_depth + 1);
        for (int i = 1; i <= n; ++i) {
            levels[depth[i]].push_back(i);
        }

        vector<long long> sum_depth(max_depth + 1, 0);
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        sum_depth[0] = 1;

        for (int d = 1; d <= max_depth; ++d) {
            long long current_sum = 0;
            for (int u : levels[d]) {
                if (d == 1) {
                    dp[u] = 1;
                } else {
                    int parent_u = p[u];
                    dp[u] = (sum_depth[d - 1] - dp[parent_u] + MOD) % MOD;
                }
                current_sum = (current_sum + dp[u]) % MOD;
            }
            sum_depth[d] = current_sum;
        }

        long long ans = 0;
        for (int d = 0; d <= max_depth; ++d) {
            ans = (ans + sum_depth[d]) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}