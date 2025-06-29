#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        int maxColor = 0;

        // Input and track the maximum color value to size arrays accordingly
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                maxColor = max(maxColor, a[i][j]);
            }

        // These will store presence and "bad" status of colors
        vector<int> hasColor(maxColor, 0);
        vector<int> hasBad(maxColor, 0);

        // Check each cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int color = a[i][j] - 1; // convert to 0-indexed
                hasColor[color] = 1;

                // Check vertical neighbor
                if (i + 1 < n && a[i][j] == a[i + 1][j])
                    hasBad[color] = 1;

                // Check horizontal neighbor
                if (j + 1 < m && a[i][j] == a[i][j + 1])
                    hasBad[color] = 1;
            }
        }

        // Count the number of colors used and bad colors
        int totalColor = 0, totalBad = 0;
        for (int i = 0; i < maxColor; ++i) {
            totalColor += hasColor[i];
            totalBad += hasBad[i];
        }

        // Output: sum(hasColor) + sum(hasBad) - 1 - max(hasBad)
        // max(hasBad) is either 0 or 1, so subtract that
        cout << (totalColor + totalBad - 1 - *max_element(hasBad.begin(), hasBad.end())) << "\n";
    }
    return 0;
}
