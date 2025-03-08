#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y, n;
        cin >> n >> x >> y;
        
        long long multiples_x = n / x;
        long long multiples_y = n / y;
        long long common_multiples = n / lcm(x, y);
        
        long long a = multiples_x - common_multiples;
        long long b = multiples_y - common_multiples;

        long long ans = 0;
        for (long long i = 0; i < a; i++) {
            ans += n;
            n--;
        }

        for (long long i = 1; i <= b; i++) {
            ans -= i;
        }

        cout << ans << endl;
    }
    
    return 0;
}
