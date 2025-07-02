#include<bits/stdc++.h>
using namespace std;

int main(){
    int tt;
    cin>>tt;
    while (tt--)
    {
        int n;
        cin>>n;
        if(n<=3){
            cout<<"ALICE\n";
            continue;
        }
        int arr[n+1]={0};
        bool alice =0;
        for(int i =0;i<n;i++){
            if(arr[i]==1)continue;
            int a = i;
            arr[a] = 1;
            bool found =0;
            for(int j =0;j<n;j++){
                if((j + a) % 4 == 3 && arr[j] != 1&&arr[j]!=1){
                    arr[j] = 1;
                    found =1;
                    break;
                }
            }
            if(found == 0){
                alice = 1;
                break;
            }
        }
        if(alice)cout<<"ALICE\n";
        else cout<<"BOB\n";
    }
    
}