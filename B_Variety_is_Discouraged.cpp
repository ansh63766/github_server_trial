// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

// int main() {
//     int t; 
//     cin >> t; // Number of test cases
//     while (t--) {
//         int n; 
//         cin >> n; // Length of the array
//         vector<int> a(n); // Array of integers
        
//         cout << "\nTest case with n = " << n << "\n";
        
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i]; // Input array elements
//         }
        
//         cout << "Input array: ";
//         for (int x : a) cout << x << " ";
//         cout << "\n";
        
//         // Step 1: Precompute frequency of each element
//         unordered_map<int, int> freq;
//         for (int x : a) freq[x]++;
        
//         cout << "Initial frequencies: \n";
//         for (auto p : freq) cout << "Element " << p.first << " -> " << p.second << " times\n";
        
//         // Step 2: Compute initial score
//         int max_score = n - freq.size(); // Initial score without removing any subarray
//         int best_l = -1, best_r = -1; // Indices of the best subarray to remove
//         int min_remaining_length = n; // Track minimum remaining array length after removal
        
//         cout << "Initial max score: " << max_score << "\n";
        
//         // Step 3: Try all possible subarrays
//         for (int l = 0; l < n; ++l) {
//             unordered_map<int, int> temp = freq; // Temporary frequency map
//             for (int r = l; r < n; ++r) {
//                 temp[a[r]]--; // Decrease frequency of a[r]
//                 if (temp[a[r]] == 0) 
//                     temp.erase(a[r]); // Remove if frequency drops to 0
                
//                 // Calculate score after removing subarray from l to r
//                 int score = (n - (r - l + 1)) - temp.size();
//                 int remaining_length = n - (r - l + 1);
                
//                 cout << "Checking subarray (" << l + 1 << ", " << r + 1 << ") -> Score: " << score << " Remaining length: " << remaining_length << "\n";
                
//                 // Update best subarray if score is better or remaining length is smaller for same score
//                 if (score > max_score || (score == max_score && remaining_length < min_remaining_length)) {
//                     max_score = score;
//                     best_l = l + 1; // +1 because problem uses 1-based indexing
//                     best_r = r + 1;
//                     min_remaining_length = remaining_length;
                    
//                     cout << "New best subarray found: " << best_l << " to " << best_r << " with max_score = " << max_score << " and remaining length = " << min_remaining_length << "\n";
//                 }
//             }
//         }
        
//         // Step 4: Output the result
//         if (best_l == -1)  {
//             cout << "0\n"; // No removal needed
//         } else {
//             cout << best_l << " " << best_r << "\n"; // Output subarray to remove
//         }
//     }
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;

// int main() {
//     int t; 
//     cin >> t;
//     while (t--) {
//         int n; 
//         cin >> n;
//         vector<int> a(n);
        
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
        
//         map<int, int> freq;
//         for (int x : a) freq[x]++;
        
//         int max_score = n - freq.size();
//         int best_l = -1, best_r = -1;
//         int min_remaining_length = n;
        
//         for (int l = 0; l < n; ++l) {
//             map<int, int> temp = freq;
//             for (int r = l; r < n; ++r) {
//                 temp[a[r]]--;
//                 if (temp[a[r]] == 0) 
//                     temp.erase(a[r]);
                
//                 int score = (n - (r - l + 1)) - temp.size();
//                 int remaining_length = n - (r - l + 1);
                
//                 if (score > max_score || (score == max_score && remaining_length < min_remaining_length)) {
//                     max_score = score;
//                     best_l = l + 1;
//                     best_r = r + 1;
//                     min_remaining_length = remaining_length;
//                 }
//             }
//         }
        
//         if (best_l == -1)  {
//             cout << "0\n";
//         } else {
//             cout << best_l << " " << best_r << "\n";
//         }
//     }
//     return 0;
// }



// #include<iostream>
// #include<vector>
// #include<unordered_set>
// using namespace std;

// int main() {
//     int t;
//     cin >> t; // Number of test cases
//     while (t--) {
//         int n;
//         cin >> n; // Length of the array
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i)
//             cin >> a[i]; // Input array elements

//         // Step 1: Find the longest subarray of consecutive distinct elements
//         int max_len = 0; // Length of the longest subarray to remove
//         int best_l = 0, best_r = 0; // Indices of the subarray to remove

//         for (int l = 0; l < n; ++l) {
//             unordered_set<int> distinct_elements; // Track distinct elements in the current window
//             int r = l;
//             while (r < n && distinct_elements.find(a[r]) == distinct_elements.end()) {
//                 distinct_elements.insert(a[r]);
//                 r++;
//             }
//             // Update best subarray if this is the longest so far
//             if (r - l > max_len) {
//                 max_len = r - l;
//                 best_l = l + 1; // 1-based indexing
//                 best_r = r; // r is already 1-based because of the while loop
//             }
//         }

//         // Step 2: Output the result
//         if (max_len <= 1) {
//             // No subarray of length > 1 found, so no removal is needed
//             cout << "0\n";
//         } else {
//             // Output the subarray to remove
//             cout << best_l << " " << best_r << "\n";
//         }
//     }
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<unordered_set>
// using namespace std;

// int main() {
//     int t;
//     cin >> t; // Number of test cases
//     while (t--) {
//         int n;
//         cin >> n; // Length of the array
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i)
//             cin >> a[i]; // Input array elements

//         cout << "\nProcessing test case with array: ";
//         for (int i = 0; i < n; ++i) cout << a[i] << " ";
//         cout << endl;

//         // Step 1: Find the longest subarray of consecutive distinct elements
//         int max_len = 0; // Length of the longest subarray to remove
//         int best_l = 0, best_r = 0; // Indices of the subarray to remove

//         for (int l = 0; l < n; ++l) {
//             cout << "\nChecking subarray starting at index " << l << " (value = " << a[l] << ")\n";
//             unordered_set<int> distinct_elements; // Track distinct elements in the current window
//             int r = l;
//             while (r < n && distinct_elements.find(a[r]) == distinct_elements.end()) {
//                 distinct_elements.insert(a[r]);
//                 cout << "  Added element at index " << r << " (value = " << a[r] << ") to distinct set\n";
//                 r++;
//             }
//             cout << "  Subarray from index " << l << " to " << r - 1 << " has " << distinct_elements.size() << " distinct elements\n";

//             // Check if the first and last elements of the remaining array are the same
//             if (l > 0 && r < n && a[l - 1] == a[r]) {
//                 cout << "  Skipping this subarray because a[l-1] = " << a[l - 1] << " and a[r] = " << a[r] << " are the same\n";
//                 continue; // Skip this subarray if the condition is met
//             }

//             // Update best subarray if this is the longest so far
//             if (r - l > max_len) {
//                 cout << "  Updating best subarray: previous max_len = " << max_len << ", new max_len = " << r - l << "\n";
//                 max_len = r - l;
//                 best_l = l + 1; // 1-based indexing
//                 best_r = r; // r is already 1-based because of the while loop
//                 cout << "  New best subarray to remove: from index " << best_l << " to " << best_r << "\n";
//             } else {
//                 cout << "  Not updating best subarray because current length " << r - l << " <= max_len " << max_len << "\n";
//             }
//         }

//         // Step 2: Output the result
//         if (max_len <= 1) {
//             // No subarray of length > 1 found, so no removal is needed
//             cout << "\nNo subarray of length > 1 found. Output: 0\n";
//         } else {
//             // Output the subarray to remove
//             cout << "\nBest subarray to remove: from index " << best_l << " to " << best_r << "\n";
//             cout << "Output: " << best_l << " " << best_r << "\n";
//         }
//     }
//     return 0;
// }


// #include<iostream>
// #include<vector>
// #include<unordered_set>
// using namespace std;

// int main() {
//     int t;
//     cin >> t; // Number of test cases
//     while (t--) {
//         int n;
//         cin >> n; // Length of the array
//         vector<int> a(n);
//         for (int i = 0; i < n; ++i)
//             cin >> a[i]; // Input array elements

//         cout << "\nProcessing test case with array: ";
//         for (int i = 0; i < n; ++i) cout << a[i] << " ";
//         cout << endl;

//         // Step 1: Find the longest subarray of consecutive distinct elements
//         int max_len = 0; // Length of the longest subarray to remove
//         int best_l = 0, best_r = 0; // Indices of the subarray to remove

//         for (int l = 0; l < n; ++l) {
//             cout << "\nChecking subarray starting at index " << l << " (value = " << a[l] << ")\n";
//             unordered_set<int> distinct_elements; // Track distinct elements in the current window
//             int r = l;
//             while (r < n && distinct_elements.find(a[r]) == distinct_elements.end()) {
//                 distinct_elements.insert(a[r]);
//                 cout << "  Added element at index " << r << " (value = " << a[r] << ") to distinct set\n";
//                 r++;
//             }
//             cout << "  Subarray from index " << l << " to " << r - 1 << " has " << distinct_elements.size() << " distinct elements\n";

//             // Check if the first and last elements of the remaining array are the same
//             if (l > 0 && r < n && a[l - 1] == a[r]) {
//                 cout << "  Skipping this subarray because a[l-1] = " << a[l - 1] << " and a[r] = " << a[r] << " are the same\n";
//                 continue; // Skip this subarray if the condition is met
//             }

//             // Check if the first element of the subarray matches the next element after the subarray
//             if (r < n && a[l] == a[r]) {
//                 cout << "  Skipping this subarray because a[l] = " << a[l] << " and a[r] = " << a[r] << " are the same\n";
//                 continue; // Skip this subarray if the condition is met
//             }

//             // Update best subarray if this is the longest so far
//             if (r - l > max_len) {
//                 cout << "  Updating best subarray: previous max_len = " << max_len << ", new max_len = " << r - l << "\n";
//                 max_len = r - l;
//                 best_l = l + 1; // 1-based indexing
//                 best_r = r; // r is already 1-based because of the while loop
//                 cout << "  New best subarray to remove: from index " << best_l << " to " << best_r << "\n";
//             } else {
//                 cout << "  Not updating best subarray because current length " << r - l << " <= max_len " << max_len << "\n";
//             }
//         }

//         // Step 2: Output the result
//         if (max_len <= 1) {
//             // No subarray of length > 1 found, so no removal is needed
//             cout << "\nNo subarray of length > 1 found. Output: 0\n";
//         } else {
//             // Output the subarray to remove
//             cout << "\nBest subarray to remove: from index " << best_l << " to " << best_r << "\n";
//             cout << "Output: " << best_l << " " << best_r << "\n";
//         }
//     }
//     return 0;
// }


#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int max_len = 0;
        int best_l = 0, best_r = 0;

        for (int l = 0; l < n; ++l) {
            unordered_set<int> distinct_elements;
            int r = l;
            while (r < n && distinct_elements.find(a[r]) == distinct_elements.end()) {
                distinct_elements.insert(a[r]);
                r++;
            }

            if (l > 0 && r < n && a[l - 1] == a[r])
                continue;

            if (r < n && a[l] == a[r])
                continue;

            if (l > 0 && a[r - 1] == a[l - 1])
                continue;

            if (r - l > max_len) {
                max_len = r - l;
                best_l = l + 1;
                best_r = r;
            }
        }

        if (max_len <= 1)
            cout << "0\n";
        else
            cout << best_l << " " << best_r << "\n";
    }
    return 0;
}