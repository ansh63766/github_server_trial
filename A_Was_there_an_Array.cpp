#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> b(n-2);
        for (int i=0; i<n-2; i++) {
            cin>>b[i];
        }
        bool valid = true;
        if (b.size() >= 3) {
            for (int i = 0; i <= (int)b.size() - 3; ++i) {
                if (b[i] == 1 && b[i + 1] == 0 && b[i + 2] == 1) {
                    valid = false;
                    break;
                }
            }
        }
        cout << (valid ? "YES" : "NO") << '\n';
    }
    return 0;
}
