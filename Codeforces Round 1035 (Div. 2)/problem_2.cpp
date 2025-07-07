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

// -------- First n Primes Generator ------------
vector<int> sieve(int n) {
    int limit = (n <= 5) ? 20 : n * (log(n) + log(log(n))) + 5;
    vector<bool> is_prime(limit + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i <= limit && sz(primes) < n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * 1LL * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    return primes;
}

//--------- Precompute Factorial and nCr -------------
vector<int> fact, inv_fact;
void precompute_factorials(int n = N6, int m = MOD) {
    fact.assign(n + 1, 1);
    inv_fact.assign(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        fact[i] = 1LL * fact[i - 1] * i % m;
    inv_fact[n] = modinv(fact[n], m);
    for (int i = n - 1; i >= 0; --i)
        inv_fact[i] = 1LL * inv_fact[i + 1] * (i + 1) % m;
}

int nCr(int n, int r, int m = MOD) {
    if (r < 0 || r > n) return 0;
    return 1LL * fact[n] * inv_fact[r] % m * inv_fact[n - r] % m;
}

// ------------------ Solver --------------------
void solve() {
    int n;
    cin >> n;
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    ll sum = accumulate(all(a), 0LL);
    ll maxi = *max_element(all(a));
    ll mn = max(0LL, maxi - (sum - maxi));

    ll dx = px - qx;
    ll dy = py - qy;
    ll dist = dx * dx + dy * dy;

    if (dist >= mn * mn && dist <= sum * sum)
        yes;
    else
        no; 
}
// ------------------- Main ---------------------
int main() {
    fastIO();
    
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
    return 0;
}