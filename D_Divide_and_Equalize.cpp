#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

vector<int> prime_factors(int x){
    vector<int> pf;
    while(x%2==0){
        pf.push_back(2);
        x=x/2;
    }
    for(int i = 3; i<=sqrt(x); i+=2){
        if(x%i==0){
            pf.push_back(i);
            x=x/i;
        }
    }
    if(x>2){
        pf.push_back(x);
    }
    return pf;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        bool ans = true;
        int prev = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] != prev) {
                ans = false;
                break;
            }
        }

        if(ans){
            cout<<"YES"<<endl;
            continue;
        }

        map<int, int> m;

        for(int i = 0; i<n; i++){
            if(a[i]<2) continue;
            vector<int> r = prime_factors(a[i]);
            for(auto it:r){
                m[it]++;
            }
        }
        bool divisible = true;
        for(auto it:m){
            if(it.second % n != 0){
                cout<<"NO"<<endl;
                divisible = false;
                break;
            }
        }
        if(divisible) cout<<"YES"<<endl;
    }

    return 0;
}
