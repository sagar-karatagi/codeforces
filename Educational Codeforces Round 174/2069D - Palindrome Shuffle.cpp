/* ISSUES :

Issue 1: Using pre/suff as constraints during traversal
You precompute frequency counts (pre and suff), but then you mutate them during traversal as you move i and j.

The logic: if (s[i] != s[j] && pre[s[i]] != suff[s[i]]) is not a correct way to decide whether you should advance i or j.

This doesn't reflect whether characters in the middle form a palindromic permutation.

Issue 2: The actual operation allows full shuffling of any substring
That means you don’t need to match characters in order; you just need to ensure that the frequency of characters in the substring can be rearranged into a palindrome.

if you find why the solution is wrong please raise a PR

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int start, int end, const string& s) {
    vector<int> pre(26, 0), suff(26, 0);
    // Precompute pre and suff frequency arrays up to end (bounded by n/2)
    for (int i = start; i <= end; ++i) {
        pre[s[i] - 'a']++;
    }
    for (int j = end; j >= start; --j) {
        suff[s[j] - 'a']++;
    }

    int i = start;
    int j = end;

    // Use pre/suff frequencies during the check
    while (i < j) {
        if (s[i] != s[j]|| pre[s[i] - 'a'] != suff[s[i] - 'a']) {
            suff[s[j] - 'a']--;
            --j;
        } else {
            pre[s[i] - 'a']--;
            ++i;
        }
    }
    return end - j + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        int start = 0, end = n - 1;

        // Skip already matching prefix and suffix
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }

        // Already a palindrome
        if (start >= end) {
            cout << 0 << '\n';
            continue;
        }

        // Maximum substring length needed is n / 2
        if (end > n / 2) end = n / 2;

        // Try solving on original and reversed strings
        int x = solve(start, end, s);
        string rev = s;
        reverse(rev.begin(), rev.end());
        int y = solve(start, end, rev);

        cout << min(x, y) << '\n';
    }

    return 0;
}
