#include <bits/stdc++.h>
using namespace std;

// ------------------- Macros -------------------
#define endl '\n'
#define pb push_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pv(x) print_vector(x)

// ------------------ Typedefs ------------------
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// ----------------- Constants ------------------
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N5 = 2e5 + 5;
const int N6 = 2e6 + 6;

// ------------- Fast I/O Setup -----------------
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// -------- Modular Arithmetic Utils -----------
ll binpow(ll a, ll b, ll m = MOD) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a, ll m = MOD) {
    return binpow(a, m - 2, m);
}

// ------------- Vector Utilities ---------------
template<typename T>
void print_vector(const vector<T>& vec, char sep = ' ') {
    for (const T& x : vec) cout << x << sep;
    cout << '\n';
}

// ------------------ Solver --------------------
void solve() {
     int n,k;
     cin>>n;
     vi a(n);
     for(int&x:a)cin>>x;
     cout<<min(2*a[0],a[0]+a[1])<<endl;
     
}

// ------------------- Main ---------------------
int main() {
    fastIO();
    
    int tt = 1;
    
    cin >> tt;
    while (tt--) solve();
    return 0;
}