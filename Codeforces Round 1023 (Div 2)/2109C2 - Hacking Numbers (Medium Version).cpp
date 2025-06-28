#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    cout << "add " << n << endl;
    int x;
    cin >> x;

    cout << "div " << n << endl;
    cin >> x;

    cout<< "add "<< 1 <<endl;
    cin>>x;

    cout << "add " << n - 1 << endl;
    cin >> x;

    cout << "!" << endl;
    cin >> x;
    assert(x == 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
