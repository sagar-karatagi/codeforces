/*
 * -----------------------------------------------------------------------------
 * Author      : Sagar Karatagi
 * GitHub      : https://github.com/sagar-karatagi
 * Problem     : Custom Array Analysis (Prefix Max + Reversed Suffix Sum)
 * Verdict     : ✅ Accepted
 * Language    : C++23 (GCC 14-64, msys2)
 * Time        : Efficient per test case - O(n)
 * Memory      : Acceptable under constraints
 * Date        : 2025-06-28
 * Submission  : Local/Practice (reference from GitHub/CF logs)
 * -----------------------------------------------------------------------------
 *
 * Problem Description:
 *  For each test case, given an array `a[]` of size `n`, compute:
 *
 *      result[i] = suffix_sum[i] - a[i] + prefix_max[i]
 *
 *  where:
 *    - prefix_max[i] = maximum of a[0] to a[i] (i.e., from the left)
 *    - suffix_sum[i] = sum of a[i] to a[n-1] (i.e., from the right)
 *
 *  However, instead of computing suffix_sum in forward direction,
 *  this implementation stores it in reverse order during input to
 *  facilitate right-to-left traversal.
 *
 * Implementation Notes:
 *  - All arithmetic is performed with `int64_t` to avoid overflow.
 *  - Vector preallocation and indexing are optimized.
 *
 * Example Input:
 *   1
 *   4
 *   3 1 4 2
 *
 * Output:
 *   8 7 6 4
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;

        vector<int64_t> pre(n);         // Prefix max
        vector<int64_t> a(n);           // Input array
        vector<int64_t> prefixSum(n);   // Reverse suffix sum

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        pre[0] = a[0];
        prefixSum[0] = a[n - 1];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + a[n - i - 1];   // Right to left sum
            pre[i] = max(pre[i - 1], a[i]);                   // Left to right max
        }

        for (int i = 0; i < n; i++) {
            cout << prefixSum[i] - a[n - i - 1] + pre[n - 1 - i] << " ";
        }
        cout << endl;
    }
    return 0;
}
