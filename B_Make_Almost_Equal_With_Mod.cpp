#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    long long t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        vector<long long> a(n);

        for(long long i = 0; i < n; i++){
            cin >> a[i];
        }

        long long ans = 2;

        while(true){
            unordered_set<long long> s;
            for(auto it : a){
                s.insert(it % ans);
            }
            if(s.size() == 2){
                cout << ans << endl;
                break;
            }
            ans *= 2;
        }
    }

    return 0;
}
