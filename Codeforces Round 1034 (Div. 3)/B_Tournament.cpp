#include<bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    cin>>tt;
    while (tt--)
    {
        int n,j,k;
        cin>>n>>j>>k;
        vector<int> arr(n,-1);
        for(int& x:arr)cin>>x;

        if(k==1){
            if(*max_element(arr.begin(),arr.end())==arr[j-1]){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
            continue;
        }
        cout<<"YES\n";
    }
    
}