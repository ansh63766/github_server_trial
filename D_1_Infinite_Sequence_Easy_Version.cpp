#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int len;
vector<int> seq;
vector<int> xored;
int baseX;

int calculateX(ll idx) {
    if(idx <= len) return xored[(int)idx];
    if(idx & 1LL) {
        if(len % 2 == 0)
            return baseX ^ xored[len/2];
        else
            return baseX;
    } else {
        if(len % 2 == 0)
            return baseX ^ ( calculateX(idx/2) ^ xored[len/2] );
        else
            return baseX ^ calculateX(idx/2);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> len >> l >> r;
        seq.resize(len);
        for (int i = 0; i < len; i++){
            cin >> seq[i];
        }

        xored.resize(len+1);
        xored[0] = 0;
        for (int i = 1; i <= len; i++){
            xored[i] = xored[i-1] ^ seq[i-1];
        }
        baseX = xored[len];

        int result = 0;
        if(l <= len){
            result = seq[(int)l - 1];
        } else {
            ll idx = l / 2;
            result = calculateX(idx);
        }

        cout << result << "\n";
    }
    return 0;
}
