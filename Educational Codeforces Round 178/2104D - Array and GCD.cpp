/*
 * ---------------------------------------------------------------------------
 * Author      : Sagar Karatagi
 * GitHub      : https://github.com/sagar-karatagi
 * Problem     : Codeforces 2104D - Array and GCD
 * Submission  : Accepted (186 ms / 11800 KB)
 * Language    : C++23 (GCC 14-64, msys2)
 * Verdict     : ✅ Accepted
 * Date        : 2025-06-28 08:23 (UTC+5.5)
 * Submission  : https://codeforces.com/contest/2104/submission/326354620
 * ---------------------------------------------------------------------------
 *
 * Problem Summary:
 *   - You are given an array `a` of size `n`.
 *   - You must find the **minimum number of elements** you need to remove
 *     from the array such that the sum of the remaining top-k elements
 *     is greater than or equal to the sum of the first `k` prime numbers
 *     for the **maximum such k**.
 *
 * Key Idea:
 *   - Precompute the first N primes and their prefix sums.
 *   - Sort the array in decreasing order and compute prefix sums of top-k values.
 *   - Use binary search to find the largest `k` such that:
 *     sum of top `k` elements ≥ sum of first `k` primes.
 *   - The answer will be `n - k`, the number of elements not used.
 */

#include <bits/stdc++.h>
using namespace std;

// Type aliasing and fast I/O
#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(0);
#define endl '\n'

// Upper bound on required number of primes (enough for n ≤ 2e5)
const int MAX_N = 4e5 + 10;

// Generate all prime numbers up to `limit` using Sieve of Eratosthenes
vector<int> generate_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit && primes.size() < MAX_N; ++i) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int32_t main() {
    fast_io;

    int t;
    cin >> t;

    // Precompute primes and their prefix sums
    vector<int> primes = generate_primes(6e6);
    vector<long long> pre(primes.size());
    pre[0] = primes[0];
    for (int i = 1; i < primes.size(); i++) {
        pre[i] = pre[i - 1] + primes[i];
    }

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long total = 0;
        for (int &x : a) {
            cin >> x;
            total += x;
        }

        sort(a.rbegin(), a.rend());  // Sort in descending order
        vector<long long> sum_a(n);
        sum_a[0] = a[0];
        for (int i = 1; i < n; ++i)
            sum_a[i] = sum_a[i - 1] + a[i];

        int low = 1, high = n, ans = n;

        // Binary search to find max `k` where sum_a[k-1] ≥ pre[k-1]
        while (low <= high) {
            int mid = (low + high) / 2;
            if (pre[mid - 1] <= sum_a[mid - 1]) {
                ans = n - mid;     // Elements to remove
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
