#include <iostream>
using namespace std;
int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            odd += (temp & 1);
        }
        even = n - odd;
        if (odd % 2 == 0)
        {
            if ((odd / 2) % 2 == 0)
                cout << "Alice";
            else
                cout << "Bob";
        }
        else
        {
            if ((1 + (odd / 2) % 2) % 2 == 0 ||((1 + (odd / 2) % 2) % 2 == 1 && even%2==1) )
            {
                cout << "Alice";
            }
            else
            {
                cout << "Bob";
            }
        }
        cout << endl;
    }
}