#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> sum_a(n);
        vector<int> max_b(n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            sum_a[i] = sum;
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            maxi = max(b[i], maxi);
            max_b[i] = maxi;
        }

        k--;
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, sum_a[i] + (k - i) * max_b[i]);
            if(i==k) break;
        }

        cout << ans << endl;
    }

    return 0;
}