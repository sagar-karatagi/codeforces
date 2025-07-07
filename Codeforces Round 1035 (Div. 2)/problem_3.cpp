#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

void solve(){
	ll N, L, R, K;
	cin >> N >> L >> R >> K;
	if(N % 2 == 1){
		cout << L << '\n';
		return;
	}
	if(N == 2){
		cout << -1 << '\n';
		return;
	}
	ll f = 63 - __builtin_clzll(L);
	if((ll(1) << (f+1)) <= R){
		if(K >= N-1){
			cout << (ll(1) << (f+1)) << '\n';
		} else {
			cout << L << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}
