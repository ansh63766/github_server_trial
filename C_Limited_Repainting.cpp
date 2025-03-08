#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        
        int max_a = *max_element(a.begin(), a.end());
        int low = 0, high = max_a, ans = max_a;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int cnt = 0;
            bool in_allowed = false;
            bool has_required = false;
            
            for (int i = 0; i < n; ++i) {
                bool forbidden = (s[i] == 'R' && a[i] > mid);
                bool required = (s[i] == 'B' && a[i] > mid);
                
                if (forbidden) {
                    if (in_allowed) {
                        if (has_required) {
                            cnt++;
                        }
                        in_allowed = false;
                        has_required = false;
                    }
                } else {
                    if (!in_allowed) {
                        in_allowed = true;
                    }
                    if (required) {
                        has_required = true;
                    }
                }
            }
            
            if (in_allowed && has_required) {
                cnt++;
            }
            
            if (cnt <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}