#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while (tt--)
    {
        int n,k;
        string s;
        cin>>n>>k;
        cin>>s;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            cnt+=(s[i]=='1');
        }
        if(n%2==1){
            n--;
        }
        if(cnt <= k){
            cout<<"ALICE\n";
            continue;
        }
        if((n/2)>=k){
            cout<<"BOB\n";
        }else{
            cout<<"ALICE\n";
        }
    }
    
}