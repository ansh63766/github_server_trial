#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        
        int left = 0, right = n - 1;
        int firstMismatch = -1, lastMismatch = -1;
        
        // Debugging: print the string
        cout << "Processing string: " << s << endl;
        
        // Find the first and last mismatched positions
        while (left < right) {
            cout << "Comparing s[" << left << "] = " << s[left] << " with s[" << right << "] = " << s[right] << endl;
            
            if (s[left] != s[right]) {
                if (firstMismatch == -1) firstMismatch = left;  // Record the first mismatch
                lastMismatch = right;  // Update the last mismatch position
                
                // Debugging: print the mismatch details
                cout << "Mismatch found at s[" << left << "] = " << s[left] << " and s[" << right << "] = " << s[right] << endl;
            }
            left++;
            right--;
        }
        
        // Debugging: print the first and last mismatch positions
        cout << "First mismatch position: " << firstMismatch << endl;
        cout << "Last mismatch position: " << lastMismatch << endl;
        
        // If no mismatch was found, the string is already a palindrome
        if (firstMismatch == -1) {
            cout << "No mismatch, string is already a palindrome. Output: 0" << endl;
            cout << 0 << endl;
        } else {
            // The minimal substring length to shuffle
            int substringLength = lastMismatch - firstMismatch;
            
            // Debugging: print the length of the substring to shuffle
            cout << "Length of the substring to shuffle: " << substringLength << endl;
            cout << substringLength << endl;
        }
    }
    return 0;
}
