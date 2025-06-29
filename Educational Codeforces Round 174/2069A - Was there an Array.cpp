/*
 * Problem: A - Was there an Array?
 * Online Judge: Codeforces
 * Submission ID: 326530949
 * Submission Time: Jun/29/2025 18:43 UTC+5.5
 * Author: sagar_karatagi
 * Language: C++23 (GCC 14-64, msys2)
 * Verdict: Accepted
 * Time: 93 ms
 * Memory: 0 KB
 *
 * Problem Link: https://codeforces.com/contest/2069/problem/A
 *
 * Description:
 * Given a binary array `b` of size n-2 (representing the "equality characteristic" of an array `a`),
 * determine whether a corresponding array `a` exists such that:
 *
 * - b[i] = 1 ⟺ a[i+1] == a[i] == a[i+2]
 * - b[i] = 0 ⟺ at least one of a[i+1] ≠ a[i] or a[i+1] ≠ a[i+2]
 *
 * Observation:
 * The only impossible case is if there exists a pattern `b[i-1] == 1`, `b[i] == 0`, `b[i+1] == 1`.
 * This creates a contradiction in values of array `a` and makes such an array impossible to construct.
 *
 * Solution:
 * - For each test case, scan the input array `b` and look for the pattern 1 0 1.
 * - If such a pattern is found, output "NO", otherwise output "YES".
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Input the b array of size (n - 2)
        vector<int> b(n - 2);
        for (int i = 0; i < n - 2; ++i) {
            cin >> b[i];
        }

        // Flag to detect the invalid "1 0 1" pattern
        bool contradiction = false;

        // We check from b[1] to b[n-4] inclusive, and compare b[i-1], b[i], b[i+1]
        for (int i = 1; i + 1 < b.size(); ++i) {
            if (b[i - 1] == 1 && b[i] == 0 && b[i + 1] == 1) {
                contradiction = true;
                break;
            }
        }

        // Output result
        cout << (contradiction ? "NO" : "YES") << '\n';
    }

    return 0;
}
