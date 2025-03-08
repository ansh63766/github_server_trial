#include <bits/stdc++.h>
using namespace std;

int solve(int l, int k, vector<int>& prefix, int n){
    int left = l, right = n-1;
    int result = l;

    while(left <= right){
        int mid = (left + right) / 2;

        // Calculate AND from l to mid
        int f_l_mid = (l > 0) ? prefix[mid] & ~prefix[l-1] : prefix[mid];

        // Check if AND is greater than or equal to k
        if(f_l_mid >= k){
            result = mid;  // If valid, try for larger r (move right)
            left = mid + 1;
        }
        else{
            right = mid - 1;  // If not valid, try smaller r (move left)
        }
    }

    return result;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        // Create the prefix AND array
        vector<int> prefix(n);
        prefix[0] = v[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] & v[i];
        }

        int q;
        cin >> q;
        while(q--){
            int l, k; 
            cin >> l >> k;
            l--;  // Adjust for 0-based indexing

            // Call the solve function to find the result for this query
            int ans = solve(l, k, prefix, n);

            // Output the result
            cout << ans + 1 << " ";  // Convert back to 1-based indexing for the output
        }
        cout << endl;
    }

    return 0;
}
