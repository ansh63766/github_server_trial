#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> grid(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        
        unordered_map<int, bool> has_adjacent;
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int color = grid[i][j];
                freq[color]++;
                
                if (has_adjacent[color] == false) {
                    if (j + 1 < m && grid[i][j] == grid[i][j + 1]) {
                        has_adjacent[color] = true;
                    }
                    if (i + 1 < n && grid[i][j] == grid[i + 1][j]) {
                        has_adjacent[color] = true;
                    }
                }
            }
        }
        
        int sum_new = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int color = it->first;
            if (has_adjacent[color]) {
                sum_new += 2;
            } else {
                sum_new += 1;
            }
        }
        
        int min_sum_c = INT_MAX;
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            int color = it->first;
            int steps;
            
            if (has_adjacent[color]) {
                steps = sum_new - 2;
            } else {
                steps = sum_new - 1;
            }
            
            if (steps < min_sum_c) {
                min_sum_c = steps;
            }
        }
        
        int ans;
        if (sum_new < min_sum_c) {
            ans = sum_new;
        } else {
            ans = min_sum_c;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
