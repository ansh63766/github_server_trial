// 1917B - Erase First or Second Letter

// logic:
// so basically keep a letter fixed and then the no of strings will be the number of suffixes.
// now there will be repitions with this logic,
// so to avoid this we only count the no of strings for first occured letter not all letters and then add the total sum.
// for eg, ababa:
// a - ababa, aaba, aba, aa, a
// b - baba, bba, ba, b
// a - aba, aa, a
// b - ba, b

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        long long ans = 0;

        vector<bool> v(26, 0);

        for(int i = 0; i<n; i++){
            if(!v[s[i] - 'a']){
                v[s[i] - 'a'] = 1;
                ans += (n-i);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}