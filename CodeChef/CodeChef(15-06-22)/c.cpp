#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define ht unordered_map
#define uset unordered_set
#define ll long long int
#define lld long double
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int z = 0;
        string g = "";
        for (int i = 0; i < n - 1; i += 2)
        {
            z = (s[i] + s[i + 1]);
            if (z == 96)
            {
                g += 'A';
            }
            else if (z == 97)
            {
                if (s[i] == '1')
                {
                    g += 'C';
                }
                else
                {
                    g += 'T';
                }
            }
            else if (z == 98)
            {
                g += 'G';
            }
            z = 0;
        }
        cout << g << el;
    }
}