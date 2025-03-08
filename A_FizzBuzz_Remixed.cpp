#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long cycle = n/15;
        long long rem = n%15;
        long long ans = cycle*3+min(rem+1,3LL);
        cout<<ans<<endl;
    }
    return 0;
}