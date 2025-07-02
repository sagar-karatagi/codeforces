#include <bits/stdc++.h>

using namespace std;
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, -1);
        vector<int> prefixMin(n), suffixMax(n);
        for (int &x : arr)
            cin >> x;
        prefixMin[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixMin[i] = min(prefixMin[i - 1], arr[i]);
        }
        suffixMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }
        

        string s = "1";
        for(int i = 1;i<n-1;i++){
            if( arr[i]<= prefixMin[i-1] || arr[i]>=suffixMax[i+1]){
                s+="1";
            }else{
                s+="0";
            }
        }
        if(n>1)
            s+="1";
        cout<<s<<"\n";
    }
}