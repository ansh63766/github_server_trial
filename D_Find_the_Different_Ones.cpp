#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; 
        cin>>n;

        vector<int> a(n);
        vector<int> diff;
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        for(int i = 0; i<n-1; i++){
            if(a[i]!=a[i+1]){
                diff.push_back(i);
            }
        }
        
        int q;
        cin>>q;

        for(int k = 0; k<q; k++){
            int l, r;
            cin>>l>>r;

            l--, r--;

            int lb = lower_bound(diff.begin(), diff.end(), l) - diff.begin();

            if(lb<diff.size() && diff[lb]<r){
                cout<<diff[lb]+1<<" "<<diff[lb]+2<<endl;
            }
            else{
                cout<<"-1"<<" "<<"-1"<<endl;
            }
        }
    }

    return 0;
}