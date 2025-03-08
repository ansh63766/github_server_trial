// APPROACH-1

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<pair<int, int>> a, b, c;

//         // Input for vector a
//         for (int i = 0; i < n; i++) {
//             int x;
//             cin >> x;
//             a.push_back({x, i});
//         }

//         // Input for vector b
//         for (int i = 0; i < n; i++) {
//             int x;
//             cin >> x;
//             b.push_back({x, i});
//         }

//         // Input for vector c
//         for (int i = 0; i < n; i++) {
//             int x;
//             cin >> x;
//             c.push_back({x, i});
//         }

//         // Sort vectors a, b, and c in descending order
//         sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
//             return x.first > y.first;
//         });

//         sort(b.begin(), b.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
//             return x.first > y.first;
//         });

//         sort(c.begin(), c.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
//             return x.first > y.first;
//         });

//         // Select the first non-coinciding days
//         int maxSum = 0;

//         // Iterate through the top 3 candidates for each activity
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 for (int k = 0; k < 3; k++) {
//                     // Check if the days are distinct
//                     if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
//                         // Calculate the sum of friends
//                         int currentSum = a[i].first + b[j].first + c[k].first;
//                         // Update the maximum sum
//                         if (currentSum > maxSum) {
//                             maxSum = currentSum;
//                         }
//                     }
//                 }
//             }
//         }

//         // Output the maximum sum
//         cout << maxSum << endl;
//     }

//     return 0;
// }


// APPROACH - 2 : SPACE OPTIMIZED
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> a, b, c;

        // Input for vector a
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back({x, i});
        }

        // Input for vector b
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            b.push_back({x, i});
        }

        // Input for vector c
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            c.push_back({x, i});
        }

        // Sort vectors a, b, and c in descending order
        sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });

        sort(b.begin(), b.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });

        sort(c.begin(), c.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });

        // Select the first non-coinciding days
        int maxSum = 0;

        // Iterate through the top 3 candidates for each activity
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    // Check if the days are distinct
                    if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
                        // Calculate the sum of friends
                        int currentSum = a[i].first + b[j].first + c[k].first;
                        // Update the maximum sum
                        if (currentSum > maxSum) {
                            maxSum = currentSum;
                        }
                    }
                }
            }
        }

        // Output the maximum sum
        cout << maxSum << endl;
    }

    return 0;
}