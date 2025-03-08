#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Initialize the last elements of the two subsequences
        int s = INT_MAX; // Last element of subsequence s
        int t = INT_MAX; // Last element of subsequence t
        int penalty = 0; // Total penalty

        for (int i = 0; i < n; i++) {
            if (s > t) {
                swap(s, t); // Ensure s is always the smaller one
            }

            if (a[i] <= s) {
                s = a[i]; // Assign to subsequence s
            } else if (a[i] <= t) {
                t = a[i]; // Assign to subsequence t
            } else {
                // If a[i] is greater than both s and t, assign to the smaller one
                // to minimize the penalty
                s = a[i];
                penalty++;
            }
        }

        cout << penalty << endl;
    }
}