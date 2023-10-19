#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    // return 0;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int c_o = 0;
        int c_e = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2)
            {
                c_o++;
            }
            else
            {
                c_e++;
            }
        }
        if (c_o % 2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
