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
        char ch[8][8];
        int r = 0;
        int c = 0;
        for (int i = 0; i < 8; i++)
        {
            for (int k = 0; k < 8; k++)
            {
                cin >> ch[i][k];
            }
        }
        int g[8] = {0};
        for (int i = 1; i < 7; i++)
        {

            for (int j = 1; j < 7; j++)
            {
                if (ch[i][j] == '#')
                {
                    if (ch[i - 1][j - 1] == '#' and ch[i + 1][j + 1] == '#' and ch[i + 1][j - 1] == '#' and ch[i - 1][j + 1] == '#')
                    {
                        r = i;
                        c = j;
                    }
                }
            }
        }
        cout << r + 1 << " " << c + 1 << el;
    }
}