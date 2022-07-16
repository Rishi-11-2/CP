#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n + 1];
    cin >> arr;
    int i = 0;
    int t = 0;
    bool check = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - i - 1])
            check = 0;
    }
    if (check == 1)
        cout << "PALINDROME";
    else
        cout << "Not a palindrome";
}
