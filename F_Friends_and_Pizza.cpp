#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> s(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int bad_mask = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 != 0) {
            bad_mask |= (1 << i);
        }
    }
    int non_bad_mask = ((1 << n) - 1) ^ bad_mask;

    vector<int> sum_odd(1 << n, 0);
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i) && (a[i] % 2 != 0)) {
                sum_odd[mask] += a[i];
            }
        }
    }

    vector<int> even_sum(1 << n, 0);
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if ((mask & (1 << i)) && (a[i] % 2 == 0)) {
                even_sum[mask] += a[i];
            }
        }
    }

    map<pair<int, int>, int> group;
    for (const string& str : s) {
        int mask = 0;
        for (char c : str) {
            mask |= (1 << (c - 'A'));
        }
        int s_part = mask & bad_mask;
        int a_part = mask & non_bad_mask;
        group[{s_part, a_part}]++;
    }

    vector<pair<pair<int, int>, int>> groups;
    for (const auto& entry : group) {
        groups.emplace_back(entry.first, entry.second);
    }

    int total_sum = accumulate(a.begin(), a.end(), 0);
    vector<long long> ans(total_sum + 1, 0);

    int len = groups.size();
    for (int i = 0; i < len; ++i) {
        auto& [s1_a1, cnt1] = groups[i];
        int s1 = s1_a1.first;
        int a1 = s1_a1.second;

        for (int j = i; j < len; ++j) {
            auto& [s2_a2, cnt2] = groups[j];
            int s2 = s2_a2.first;
            int a2 = s2_a2.second;

            if ((s1 & s2) != 0) continue;

            int current_sum_odd = sum_odd[s1] + sum_odd[s2];
            int current_even = even_sum[a1 | a2];
            int sum_in_union = current_sum_odd + current_even;
            int k = total_sum - sum_in_union;
            if (k < 0 || k > total_sum) continue;

            long long pairs = (i == j) ? 1LL * cnt1 * (cnt1 - 1) / 2 : 1LL * cnt1 * cnt2;
            ans[k] += pairs;
        }
    }

    for (int k = 0; k <= total_sum; ++k) {
        cout << ans[k] << " ";
    }
    cout << endl;

    return 0;
}