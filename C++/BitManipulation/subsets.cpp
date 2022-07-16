#include <bits/stdc++.h>
using namespace std;
void subsets(char arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) // checking for bit using get bit i.e. whether it is 1 or 0
            {
                cout << arr[j] << "  ";
            }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    char c[n];
    cin >> c;
    subsets(c, n);
}