#include <bits/stdc++.h>
using namespace std;
 
vector<bool> comp(1e5+1);
vector<int> primes;
 
void sieve(){
    for(int i=2; i*i<=1e5; i++)
        if(!comp[i])
            for(int j=i*i; j<=1e5; j+=i)
                comp[j] = true;
    for(int i=2; i<=1e5; i++)
        if(!comp[i])
            primes.push_back(i);
}
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(auto it = primes.rbegin(); it != primes.rend(); ++it){
        vector<int> cycle;
        for(int i=*it; i<=n; i+=*it)
            if(!p[i])
                cycle.push_back(i);
        for(int i=0; i<cycle.size(); i++)
            p[cycle[i]] = cycle[(i+1) % cycle.size()];
    }
    for(int i=1; i<=n; i++)
        if(!p[i])
            p[i] = i;
    for(int i=1; i<=n; i++)
        cout << p[i] << (i != n ? ' ' : '\n');
}
 
int main(){
    sieve();
    int t;
    cin >> t;
    while(t--) solve();
}
